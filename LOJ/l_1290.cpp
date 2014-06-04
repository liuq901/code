#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
namespace KM
{
    const int N=110,inf=1<<30;
    int n,b[N],dx[N],dy[N],slack[N],a[N][N];
    bool f[N],g[N];
    bool hungary(int x)
    {
        if (x==0)
            return(true);
        f[x]=true;
        for (int y=1;y<=n;y++)
        {
            if (g[y])
                continue;
            int t=dx[x]+dy[y]-a[x][y];
            if (t==0)
            {
                g[y]=true;
                if (hungary(b[y]))
                {
                    b[y]=x;
                    return(true);
                }
            }
            else
                slack[y]=min(t,slack[y]);
        }
        return(false);
    }
    int solve()
    {
        memset(dx,-63,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dx[i]=max(dx[i],a[i][j]);
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            memset(slack,63,sizeof(slack));
            while (1)
            {
                memset(f,0,sizeof(f));
                memset(g,0,sizeof(g));
                if (hungary(i))
                    break;
                int d=inf;
                for (int i=1;i<=n;i++)
                    if (!g[i])
                        d=min(d,slack[i]);
                for (int i=1;i<=n;i++)
                {
                    if (f[i])
                        dx[i]-=d;
                    if (g[i])
                        dy[i]+=d;
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            ans+=a[b[i]][i];
        return(-ans);
    }
}
vector <int> a[110],b[110];
int c1[110],c2[110];
void dfs(int x,const vector <int> a[],int c[])
{
    c[x]=1;
    for (int i=0;i<a[x].size();i++)
    {
        dfs(a[x][i],a,c);
        c[x]+=c[a[x][i]];
    }
}
int calc(int x,int y)
{
    int n=max(a[x].size(),b[y].size()),tmp[110][110];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            int &now=tmp[i+1][j+1];
            if (i>=a[x].size())
                now=c2[b[y][j]];
            else if (j>=b[y].size())
                now=c1[a[x][i]];
            else
                now=calc(a[x][i],b[y][j]);
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            KM::a[i][j]=-tmp[i][j];
    KM::n=n;
    return(KM::solve());
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<=n;i++)
            a[i].clear();
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x].push_back(i);
        }
        int m;
        scanf("%d",&m);
        for (int i=0;i<=m;i++)
            b[i].clear();
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            b[x].push_back(i);
        }
        dfs(0,a,c1);
        dfs(0,b,c2);
        static int id=0;
        printf("Case %d: %d\n",++id,calc(0,0));
    }
    return(0);
}

