#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
ll Sqrt(ll x)
{
    ll q=sqrt(double(x));
    for (int i=1;i<=5;i++)
        if (q>0)
            q--;
    while (q*q<=x)
        q++;
    return(q-1);
}
ll calc(ll n)
{
    if (n==0)
        return(0);
    ll x=Sqrt(n);
    if (x%2==0)
    {
        ll l=1,r=2*(x-1)-1,m=(r-l)/4+1;
        return((l+r)/2*m+n-x*x);
    }
    else
    {
        ll l=1,r=2*x-1,m=(r-l)/4+1;
        return((l+r)/2*m);
    }
}
int main()
{
    ll a,b;
    while (scanf("%llu%llu",&a,&b)==2)
    {
        a++,b++;
        printf("%llu\n",calc(b)-calc(a-1));
    }
    return(0);
}

