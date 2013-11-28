#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int ans,limit,u[50],v[50],dep[50],l[50],r[50];
vector <int> a[50];
char s[50];
void getdep(int x)
{
    if (x==0)
        return;
    a[dep[x]].push_back(x);
    dep[l[x]]=dep[r[x]]=dep[x]+1;
    getdep(l[x]);
    getdep(r[x]);
}
int check()
{
    int mi=1;
    for (int i=limit;i;i--)
        for (int j=0;j<a[i].size();j++)
        {
            int x=a[i][j];
            if (l[x])
                u[x]=u[l[x]]+u[r[x]];
            else if (v[x]==-1)
                u[x]=mi;
            else
                u[x]=v[x];
            if (u[x]<mi)
                return(-1);
            mi=u[x];
        }
    return(u[1]<=100);
}
void dfs(int dep,int id,int last)
{
    if (dep==0)
    {
        ans+=v[1]==100;
        return;
    }
    if (id==a[dep].size())
    {
        dfs(dep-1,0,last);
        return;
    }
    int x=a[dep][id];
    if (l[x])
    {
        v[x]=v[l[x]]+v[r[x]];
        dfs(dep,id+1,v[x]);
        v[x]=-1;
        return;
    }
    for (int i=last;i<=99;i++)
    {
        v[x]=i;
        int p=check();
        if (p==0)
            break;
        if (p==-1)
            continue;
        dfs(dep,id+1,v[x]);
    }
    v[x]=-1;
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for (int i=0;i<=n;i++)
            a[i].clear();
        int m=1;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            int len=strlen(s),x=1;
            for (int j=0;j<len;j++)
                if (s[j]=='0')
                {
                    if (!l[x])
                        l[x]=++m;
                    x=l[x];
                }
                else
                {
                    if (!r[x])
                        r[x]=++m;
                    x=r[x];
                }
        }
        dep[1]=1;
        getdep(1);
        limit=*max_element(dep+1,dep+m+1);
        memset(v,-1,sizeof(v));
        ans=0;
        dfs(limit,0,1);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

