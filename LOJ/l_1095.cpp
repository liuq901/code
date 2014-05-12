#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int fac[1010],c[1010][1010];
void init()
{
    const int n=1000;
    fac[0]=1;
    for (int i=1;i<=n;i++)
        fac[i]=ll(fac[i-1])*i%mod;
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=0;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        int ans=0;
        for (int i=0;i<=m-K;i++)
        {
            int now=ll(c[m-K][i])*fac[n-K-i]%mod;
            if (i&1)
                ans=(ans-now+mod)%mod;
            else
                ans=(ans+now)%mod;
        }
        ans=ll(ans)*c[m][K]%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

