#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
ll check(ll n)
{
    int p=max(1,int(sqrt(double(n))-3));
    while (ll(p)*p<n)
        p++;
    if (ll(p)*p==n)
        return(n);
    else
        return(-1);
}
int main()
{
    ll n;
    scanf("%lld",&n);
    ll ans=1;
    for (int i=2;i<=10000000;i++)
    {
        if (n==1)
            break;
        if (n%i!=0)
            continue;
        int sum=0;
        while (n%i==0)
        {
            ans*=i;
            n/=i;
            sum++;
        }
        if (sum&1)
            ans/=i;
    }
    ll k=check(n);
    if (k!=-1)
        ans*=k;
    printf("%lld\n",ans);
    return(0);
}

