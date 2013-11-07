#include <cstdio>
typedef long long ll;
const int n=1000000;
inline ll sqr(ll x)
{
    return(x*x);
}
int main()
{
    ll ans=0;
    for (int i=3;;i+=2)
    {
        int l=1,r=i/2,now=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (sqr(i)-sqr(2*mid-1)<=n)
                r=mid-1,now=mid;
            else
                l=mid+1;
        }
        if (now==-1)
            break;
        ans+=i/2-now+1;
    }
    for (int i=4;;i+=2)
    {
        int l=1,r=i/2-1,now=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (sqr(i)-sqr(2*mid)<=n)
                r=mid-1,now=mid;
            else
                l=mid+1;
        }
        if (now==-1)
            break;
        ans+=i/2-now;
    }
    printf("%lld\n",ans);
    return(0);
}

