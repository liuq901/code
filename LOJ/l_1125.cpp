#include <cstdio>
#include <cstring>
typedef long long ll;
int a[210];
ll f[210][20][20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int K,m;
            scanf("%d%d",&K,&m);
            memset(f,0,sizeof(f));
            f[0][0][0]=1;
            for (int i=1;i<=n;i++)
                for (int j=0;j<=m;j++)
                    for (int k=0;k<K;k++)
                    {
                        f[i][j][k]+=f[i-1][j][k];
                        if (j>0)
                            f[i][j][(k+a[i]%K+K)%K]+=f[i-1][j-1][k];
                    }
            printf("%lld\n",f[n][m][0]);
        }
    }
    return(0);
}

