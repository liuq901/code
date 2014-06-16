#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int tot,dep[100010],b[100010],a[200010][2];
bool vis[100010];
int dfs(int x,int father)
{
    vis[x]=true;
    tot++;
    int ret=x;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dep[y]=dep[x]+1;
        int tmp=dfs(y,x);
        if (dep[tmp]>dep[ret])
            ret=tmp;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        vector <pair <int,int> > p;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
            if (!vis[i])
            {
                dep[i]=1;
                int k=dfs(i,0);
                tot=0;
                dep[k]=1;
                k=dfs(k,0);
                p.push_back(make_pair(dep[k],tot));
            }
        sort(p.begin(),p.end());
        vector <pair <int,int> > s;
        for (int i=0;i<p.size();i++)
        {
            while (!s.empty() && s.back().second<=p[i].second)
                s.pop_back();
            s.push_back(p[i]);
        }
        p.clear();
        for (int i=0;i<s.size();i++)
            p.push_back(make_pair(s[i].second,s[i].first));
        reverse(p.begin(),p.end());
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            int t=lower_bound(p.begin(),p.end(),make_pair(x,-1))-p.begin();
            if (t==p.size())
                printf("impossible\n");
            else
                printf("%d\n",2*max(0,x-p[t].second)+min(x,p[t].second)-1);
        }
    }
    return(0);
}

