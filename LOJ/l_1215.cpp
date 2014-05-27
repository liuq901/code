#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
inline ll lcm(ll a,ll b)
{
    return(a*b/__gcd(a,b));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b,L;
        scanf("%lld%lld%lld",&a,&b,&L);
        a=lcm(a,b);
        ll ans=-1;
        for (ll i=1;i*i<=L;i++)
        {
            if (L%i!=0)
                continue;
            if (lcm(a,i)==L)
            {
                ans=i;
                break;
            }
            if (lcm(a,L/i)==L)
                ans=L/i;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%lld\n",ans);
    }
    return(0);
}

