#include <cstdio>
typedef long long ll;
struct frac
{
    ll a,b;
    frac(ll a=0,ll b=1):a(a),b(b){}
    ll gcd(ll a,ll b)
    {
        return(b?gcd(b,a%b):a);
    }
    frac get()
    {
        ll p=gcd(a,b);
        return(frac(a/p,b/p));
    }
    void print()
    {
        static int id=0;
        printf("Case %d: %lld/%lld\n",++id,a,b);
    }
};
inline frac operator +(const frac &a,const frac &b)
{
    frac c(a.a*b.b+a.b*b.a,a.b*b.b);
    return(c.get());
}
inline frac operator /(const frac &a,const frac &b)
{
    frac c(a.a*b.b,a.b*b.a);
    return(c.get());
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        frac ans;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans=ans+1/frac(x);
        }
        ans=n/ans;
        ans.print();
    }
    return(0);
}

