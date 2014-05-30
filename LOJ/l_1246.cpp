#include <cstdio>
const int mod=1000000007;
typedef long long ll;
int c[410][410],f[410][410];
void init()
{
    int n=400;
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for (int i=0;i<=n;i++)
    {
        f[i][0]=i==0;
        for (int j=1;j<=i;j++)
            for (int k=1;k<=i;k++)
                f[i][j]=(f[i][j]+ll(f[i-k][j-1])*c[i][k])%mod;
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
        n++,m++;
        int p=n*m/2,q=n*m-p,ans=0;
        for (int i=0;i<=K;i++)
            for (int j=0;j<=K-i;j++)
                ans=(ans+ll(c[K][i])*c[K-i][j]%mod*f[p][i]%mod*f[q][j])%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

