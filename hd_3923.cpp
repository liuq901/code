#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll mod,power[10010];
inline void checkmod(ll &a,ll b)
{
    a+=b;
    if (a>mod)
        a-=mod;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        ll ans=0;
        if (n==1)
            ans=m;
        else if (n==2)
            ans=m*(m+1)/2;
        else
        {
            mod=MOD*n*2;
            power[0]=1;
            for (int i=1;i<=n;i++)
                power[i]=(power[i-1]*m)%mod;
            for (int i=1;i<=n;i++)
                checkmod(ans,power[__gcd(n,i)]);
            if (n%2==1)
                for (int i=1;i<=n;i++)
                    checkmod(ans,power[(n+1)/2]);
            else
                for (int i=1;i<=n/2;i++)
                {
                    checkmod(ans,power[n/2]);
                    checkmod(ans,power[n/2+1]);
                }
            ans/=n*2;
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,int(ans));
    }
    return(0);
}

