#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 410
using namespace std;
int n,ans[MAXN],b[MAXN],dx[MAXN],dy[MAXN],slack[MAXN],v[MAXN],a[MAXN][MAXN];
bool f[MAXN],g[MAXN];
bool hungary(int x)
{
    if (!x)
        return(true);
    f[x]=true;
    for (int i=1;i<=n;i++)
    {
        if (g[i])
            continue;
        int t=dx[x]+dy[i]-a[x][i];
        if (t==0)
        {
            g[i]=true;
            if (hungary(b[i]))
            {
                b[i]=x;
                return(true);
            }
        }
        else
            slack[i]=min(slack[i],t);
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for (int i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m);
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                a[i][x]=v[i];
                dx[i]=max(dx[i],v[i]);
            }
        }
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            memset(f,0,sizeof(f));
            memset(g,0,sizeof(g));
            memset(slack,63,sizeof(slack));
            while (!hungary(i))
            {
                int d=1<<30;
                for (int j=1;j<=n;j++)
                    if (!g[j])
                        d=min(d,slack[j]);
                for (int j=1;j<=n;j++)
                {
                    if (f[j])
                        dx[j]-=d;
                    if (g[j])
                        dy[j]+=d;
                }
                memset(f,0,sizeof(f));
                memset(g,0,sizeof(g));
            }
        }
        for (int i=1;i<=n;i++)
            if (a[b[i]][i]==0)
                ans[b[i]]=0;
            else
                ans[b[i]]=i;
        for (int i=1;i<=n;i++)
            printf("%d%c",ans[i],i==n?'\n':' ');
        if (T)
            printf("\n");
    }
    return(0);
}

