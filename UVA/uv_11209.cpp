#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int d[210],c[210][210];
inline bool cmp(int x,int y)
{
    return(d[x]<d[y]);
}
vector <int> a[210];
bool in[210];
void spfa(int S)
{
    memset(d,63,sizeof(d));
    d[S]=0;
    in[S]=true;
    queue <int> Q;
    Q.push(S);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=0;i<a[x].size();i++)
        {
            int y=a[x][i];
            if (d[x]+c[x][y]<d[y])
            {
                d[y]=d[x]+c[x][y];
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
}
bool vis[210];
int ans,center,f[2010];
vector <int> route,best;
void dfs(int x,int T,int len)
{
    vis[x]=true;
    f[len]=x;
    route.push_back(x);
    if (len+d[x]>=ans)
        goto last;
    if (x==T)
    {
        if (len%2==0 && f[len/2]>0)
        {
            ans=len;
            best=route;
            center=f[len/2];
        }
        goto last;
    }
    for (int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        if (vis[y])
            continue;
        dfs(y,T,len+c[x][y]);
    }
last:
    vis[x]=false;
    f[len]=0;
    route.pop_back();
}
int main()
{
    int n,m,S,T;
    while (scanf("%d%d%d%d",&n,&m,&S,&T)==4)
    {
        for (int i=1;i<=n;i++)
            a[i].clear();
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            c[x][y]=c[y][x]=z;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        spfa(T);
        for (int i=1;i<=n;i++)
            sort(a[i].begin(),a[i].end(),cmp);
        ans=1<<30;
        dfs(S,T,0);
        static int id=0;
        printf("Case %d: %d\n",++id,ans/2);
        int k;
        for (int i=0;i<best.size();i++)
            if (best[i]==center)
            {
                k=i;
                break;
            }
        printf("%d",k+1);
        for (int i=0;i<=k;i++)
            printf(" %d",best[i]);
        printf("\n");
        printf("%d",best.size()-k);
        for (int i=best.size()-1;i>=k;i--)
            printf(" %d",best[i]);
        printf("\n");
    }
    return(0);
}

