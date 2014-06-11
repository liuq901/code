#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int f[100010][60];
void init()
{
    const int n=100000,m=50;
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            f[i][j]=ll(f[i-1][j])*i%mod*(i-1)%mod;
            if (i>=2)
                f[i][j]=(f[i][j]+ll(f[i-2][j-1])*(i*(i-1LL)/2%mod)%mod*(i-1))%mod;
        }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][m]);
    }
    return(0);
}

