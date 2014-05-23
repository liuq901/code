#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=100000007;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
vector <ll> a;
int ans[1000010];
void init()
{
    for (int i=2;i<=100000;i++)
    {
        ll now=ll(i)*i;
        while (now<=10000000000LL)
        {
            a.push_back(now);
            now*=i;
        }
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    ans[0]=1;
    for (int i=1;i<=1000000;i++)
        ans[i]=ll(ans[i-1])*(4*i-2)%mod*power(i+1,mod-2)%mod;
    ans[0]=0;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll l,r;
        scanf("%lld %lld",&l,&r);
        static int id=0;
        printf("Case %d: %d\n",++id,ans[upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l)]);
    }
    return(0);
}

