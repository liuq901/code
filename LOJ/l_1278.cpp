#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
bool f[10000010];
int m,p[700000];
void init()
{
    const int n=10000000;
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
}
int ans;
ll N;
vector <pair <ll,int> > b;
void dfs(int dep,ll now)
{
    if (dep==b.size())
    {
        ll t=N/now+1-now;
        ans+=now!=1 && t%2==0 && t/2>0;
        return;
    }
    for (int i=0;i<=b[dep].second;i++)
    {
        dfs(dep+1,now);
        now*=b[dep].first;
    }
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
        n<<=1;
        N=n;
        b.clear();
        for (int i=1;i<=m;i++)
        {
            if (ll(p[i])*p[i]>n)
                break;
            if (n%p[i]==0)
            {
                b.push_back(make_pair(p[i],0));
                while (n%p[i]==0)
                {
                    b.back().second++;
                    n/=p[i];
                }
            }
        }
        if (n!=1)
            b.push_back(make_pair(n,1));
        ans=0;
        dfs(0,1);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

