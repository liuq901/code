#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=1000000000000LL;
vector <ll> lucky;
void dfs(ll x)
{
    if (x>N)
        return;
    lucky.push_back(x);
    dfs(x*10+4);
    dfs(x*10+7);
}
vector <ll> a;
void gen(ll x,int start)
{
    if (x>N)
        return;
    a.push_back(x);
    for (int i=start;i<lucky.size();i++)
    {
        if (x>N/lucky[i])
            break;
        gen(x*lucky[i],i);
    }
}
void init()
{
    dfs(4);
    dfs(7);
    sort(lucky.begin(),lucky.end());
    for (int i=0;i<lucky.size();i++)
        gen(lucky[i],i);
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        static int id=0;
        printf("Case %d: %d\n",++id,upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l));
    }
    return(0);
}

