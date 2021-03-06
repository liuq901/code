#include <cstdio>
typedef long long ll;
const int mod=1000000007;
ll fact[1000010],inv[1000010],f[1010][1010];
ll power(ll x,int n)
{
    if (n==0)
        return(1);
    ll ret=power(x,n>>1);
    ret=ret*ret%mod;
    if (n&1)
        ret=ret*x%mod;
    return(ret);
}
ll C(ll n,ll m)
{
    return(fact[n]*inv[m]%mod*inv[n-m]%mod);
}
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    fact[0]=1;
    for (int i=1;i<=K;i++)
        fact[i]=fact[i-1]*i%mod;
    for (int i=0;i<=K;i++)
        inv[i]=power(fact[i],mod-2);
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            f[i][j]=(f[i-1][j-1]+f[i-1][j]*j)%mod;
    if (m==1)
        printf("%I64d\n",power(K,n));
    else
    {
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            if (i>K)
                break;
            for (int j=0;j<=i;j++)
            {
                if (i*2-j>K)
                    continue;
                ll tmp=C(K,j)*C(K-j,i-j)%mod*C(K-i,i-j)%mod*f[n][i]%mod*f[n][i]%mod*fact[i]%mod*fact[i]%mod*power(j,(m-2)*n)%mod;
                ans=(ans+tmp)%mod;
            }
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

