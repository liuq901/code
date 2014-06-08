#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=1000000000000LL;
vector <ll> a;
bool f[1000010];
int m,p[1000010];
void dfs(ll x,int first)
{
    a.push_back(x);
    for (int i=first;i<=m;i++)
    {
        ll t=i==1?2:ll(p[i])*p[i];
        if (x<=N/t)
            dfs(x*t,i);
        else
            break;
    }
}
void init()
{
    const int n=1000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
    dfs(1,1);
    sort(a.begin(),a.end());
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n;
        scanf("%lld",&n);
        static int id=0;
        printf("Case %d: %lld\n",++id,n-(upper_bound(a.begin(),a.end(),n)-a.begin()));
    }
    return(0);
}

