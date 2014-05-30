#include <cstdio>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        ll ans=0;
        for (ll i=1;i<=n;i++)
        {
            ll now=n/i,tmp=n/now;
            ans+=now*(tmp-i+1);
            i=tmp;
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

