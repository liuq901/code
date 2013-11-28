#include <cstdio>
#include <cmath>
typedef long long ll;
int n=500000000;
inline ll sqr(ll x)
{
    return(x*x);
}
int check(int a,int b)
{
    ll h=sqr(a)-sqr(b),x=ll(sqrt(h+1e-8));
    if (x*x==h && a+b<=n)
        return(2*(a+b));
    else
        return(0);
}
int main()
{
    ll ans=0;
    for (int i=3;i<=n;i+=2)
        ans+=check(i,(i+1)/2)+check(i,(i-1)/2);
    printf("%lld\n",ans);
    return(0);
}

