#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int fac[1000010],inv[1000010];
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
    const int n=1000000;
    fac[0]=inv[0]=1;
    for (int i=1;i<=n;i++)
    {
        fac[i]=ll(fac[i-1])*i%mod;
        inv[i]=power(fac[i],mod-2);
    }
}
int C(int n,int m)
{
    return(ll(fac[n])*inv[n-m]%mod*inv[m]%mod);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=1,sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans=ll(ans)*C(sum+x-1,x-1)%mod;
            sum+=x;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
}

