#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll inf=1LL<<60;
int tot,d[610],p[610],b[610],w[610],v[610],q[610],f[610][2010],a[60010][3];
ll g[610][2010];
bool vis[610];
void topsort(int n,int S)
{
    memset(vis,0,sizeof(vis));
    vis[S]=true;
    int l=1,r=0;
    for (int i=1;i<=n;i++)
        if (!d[i])
            q[++r]=i;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (vis[x])
                vis[y]=true;
            d[y]--;
            if (d[y]==0)
                q[++r]=y;
        }
    }
    tot=0;
    for (int i=1;i<=n;i++)
    {
        int x=q[i];
        if (vis[x])
            p[++tot]=x;
    }
}
int main()
{
    int n,m,W,S;
    while (scanf("%d%d%d%d",&n,&m,&W,&S)==4)
    {
        for (int i=1;i<=n;i++)
            scanf("%d%d",&w[i],&v[i]);
        memset(b,0,sizeof(b));
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            d[y]++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        }
        topsort(n,S);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=w[S];i<=W;i++)
            if (f[S][i-w[S]]+v[S]>f[S][i])
                f[S][i]=f[S][i-w[S]]+v[S];
        for (int i=1;i<=tot;i++)
        {
            int x=p[i];
            for (int j=w[x];j<=W;j++)
            {
                if (f[x][j-w[x]]+v[x]>f[x][j])
                {
                    f[x][j]=f[x][j-w[x]]+v[x];
                    g[x][j]=inf;
                }
                if (f[x][j-w[x]]+v[x]==f[x][j] && g[x][j-w[x]]<g[x][j])
                    g[x][j]=g[x][j-w[x]];
            }
            for (int j=b[x];j;j=a[j][2])
            {
                int y=a[j][0];
                for (int k=0;k<=W;k++)
                {
                    if (f[x][k]>f[y][k])
                    {
                        f[y][k]=f[x][k];
                        g[y][k]=inf;
                    }
                    if (f[x][k]==f[y][k])
                    {
                        ll t=g[x][k]+k*a[j][1];
                        if (t<g[y][k])
                            g[y][k]=t;
                    }
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=W;j++)
                if (f[i][j]>ans)
                    ans=f[i][j];
        ll energy=inf;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=W;j++)
                if (f[i][j]==ans && g[i][j]<energy)
                    energy=g[i][j];
        printf("%lld\n",energy);
    }
    return(0);
}

