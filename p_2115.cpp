#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
void gcd(ll a,ll b,ll &x,ll &y)
{
    if (!b)
    {
        x=1,y=0;
        return;
    }
    ll p,q;
    gcd(b,a%b,p,q);
    x=q,y=p-a/b*q;
}
ll calc(ll x,ll k)
{
    ll l=0,r=1<<30,ans;
    while (l<=r)
    {
        ll mid=l+r>>1,y=mid*k;
        if (x<0)
            if (x+y>=0)
            {
                ans=x+y;
                r=mid-1;
            }
            else
                l=mid+1;
        else if (x-y>=0)
        {
            ans=x-y;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return(ans);
}
int main()
{
    while (1)
    {
        ll a,b,c,k;
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
        if (!a && !b && !c && !k)
            break;
        k=1LL<<k;
        ll p=__gcd(c,k);
        if ((b-a)%p)
            printf("FOREVER\n");
        else
        {
            ll q=(b-a)/p,x,y;
            gcd(c,k,x,y);
            x*=q;
            printf("%I64d\n",calc(x,k/p));
        }
    }
    return(0);
}

