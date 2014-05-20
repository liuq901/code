#include <cstdio>
#include <cstring>
const int mod=100000007;
int f[2][15010],g[2][15010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,m;
        scanf("%d%d%d",&n,&K,&m);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        f[0][0]=1;
        for (int i=0;i<K;i++)
            g[0][i]=1;
        for (int i=1;i<=n;i++)
        {
            int u=i&1,v=u^1;
            for (int j=1;j<=m;j++)
            {
                f[u][j]=g[v][j-1];
                g[u][j]=(f[u][j]+g[u][j-1])%mod;
                if (j>=K)
                    g[u][j]=(g[u][j]-f[u][j-K]+mod)%mod;
            }
            memset(f[v],0,sizeof(f[v]));
            memset(g[v],0,sizeof(g[v]));
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n&1][m]);
    }
    return(0);
}

