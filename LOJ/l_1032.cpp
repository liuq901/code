#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        n++;
        ll ans=0;
        for (int i=0;i<=32;i++)
        {
            ll p=1LL<<i+2;
            ans+=n/p*(1LL<<i)+max(0LL,n%p-3*(1LL<<i));
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

