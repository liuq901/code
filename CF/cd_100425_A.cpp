#include <cstdio>
typedef long long ll;
ll calc(ll n,ll l,ll r)
{
    if (l>r)
        return(0);
    ll first=(n-3*l)/2+1;
    ll last=(n-3*r)/2+1;
    ll num=(r-l)/2+1;
    return((first+last)*num/2);
}
ll calc(ll n)
{
    ll p=n/3;
    if (p%2==0)
        return(calc(n,1,p-1)+calc(n,2,p));
    else
        return(calc(n,1,p)+calc(n,2,p-1));
}
ll work(ll K)
{
    ll l=1,r=2000000000,ans=0;
    while (l<=r)
    {
        ll mid=l+r>>1;
        if (calc(mid)<=K)
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    return(ans);
}
int main()
{
    ll l,r;
    scanf("%I64d%I64d",&l,&r);
    printf("%I64d\n",work(r)-work(l-1));
    return(0);
}

