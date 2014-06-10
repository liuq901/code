#include <cstdio>
typedef long long ll;
ll calc(ll n)
{
    if (n==0)
        return(0);
    if (n==1)
        return(1);
    if (n==2)
        return(0);
    if (n==3)
        return(3);
    int pos;
    for (int i=0;i<=62;i++)
        if (n>>i&1)
            pos=i;
    ll ans=0,cnt=n-(1LL<<pos)+1,tmp=1LL<<pos;
    if (!(cnt&1))
        ans|=1LL<<pos;
    for (int i=pos-1;i>=1;i--)
    {
        tmp>>=1;
        if (cnt/tmp&1 && cnt%tmp&1)
            ans|=1LL<<i;
        if (i==pos-1)
            ans^=1LL<<i;
    }
    if (cnt%4==2 || cnt%4==3)
        ans|=1;
    return(ans);
}
int Log(ll x)
{
    int cnt=0;
    while (x)
    {
        cnt++;
        x>>=1;
    }
    if (cnt==0)
        cnt=1;
    return(cnt);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        static int id=0;
        printf("Case %d: %lld\n",++id,calc(b)^calc(a-1)<<Log(b)-Log(a-1));
    }
    return(0);
}

