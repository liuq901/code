#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N=50010;
typedef long long ll;
ll ans,f[N][4],g[N][4];
int n,m,fa[N],q[N],v[N],c[N],b[N],a[N*2][2];
bool vis[N];
void bfs()
{
    memset(vis,0,sizeof(vis));
    int l,r;
    q[l=r=1]=1;
    vis[1]=true;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (!vis[y])
            {
                vis[y]=true;
                q[++r]=y;
                fa[y]=x;
            }
        }
    }
}
void dp()
{
    memset(f,-63,sizeof(f));
    memset(g,-63,sizeof(g));
    ans=-1LL<<60;
    for (int i=n;i;i--)
    {
        int x=q[i];
        for (int j=c[x];j<=m;j++)
        {
            f[x][j]=v[x];
            if (j>0)
                g[x][j]=v[x];
            ans=max(ans,ll(v[x]));
        }
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (y==fa[x])
                continue;
            for (int j=0;j<=m;j++)
                ans=max(ans,max(f[x][j]+g[y][m-j],g[x][j]+f[y][m-j]));
            for (int j=c[x];j<=m;j++)
            {
                f[x][j]=max(f[x][j],f[y][j-c[x]]+v[x]);
                g[x][j]=max(g[x][j],g[y][j-c[x]]+v[x]);
            }
            for (int j=1;j<=m;j++)
            {
                f[x][j]=max(f[x][j],f[x][j-1]);
                g[x][j]=max(g[x][j],g[x][j-1]);
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&v[i],&c[i]);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        bfs();
        dp();
        cout<<ans<<endl;
    }
    return(0);
}

