#include <cstdio>
typedef long long ll;
int a[20],p[20];
int power(int x,int y,int mod)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ret*x%mod;
        x=x*x%mod;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        ll P=1;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i],&a[i]);
            P*=p[i];
        }
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            ll tmp=P/p[i];
            ans+=a[i]*tmp*power(tmp%p[i],p[i]-2,p[i]);
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans%P);
    }
    return(0);
}

