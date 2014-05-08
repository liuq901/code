#include <cstdio>
const int mod=1000003;
typedef long long ll;
ll fac[1000010],inv[1000010];
ll power(ll x,ll y)
{
    ll ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ret*x%mod;
        x=x*x%mod;
    }
    return(ret);
}
void init()
{
    int n=1000000;
    fac[0]=inv[0]=1;
    for (int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=power(fac[i],mod-2);
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
        printf("Case %d: %lld\n",++id,fac[n]*inv[m]%mod*inv[n-m]%mod);
    }
    return(0);
}

