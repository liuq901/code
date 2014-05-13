#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int fac[2000010],inv[2000010];
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
void init()
{
    int n=2000000;
    fac[0]=inv[0]=1;
    for (int i=1;i<=n;i++)
    {
        fac[i]=ll(fac[i-1])*i%mod;
        inv[i]=power(fac[i],mod-2);
    }
}
int C(int n,int m)
{
    return(ll(fac[n])*inv[m]%mod*inv[n-m]%mod);
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
        printf("Case %d: %d\n",++id,C(n+m-1,m-1));
    }
    return(0);
}

