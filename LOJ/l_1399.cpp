#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int power(int x,ll y)
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
bool flag[1000010];
int m,p[1000010];
double l[1000010];
void init()
{
    const int n=1000000;
    for (int i=2;i*i<=n;i++)
    {
        if (flag[i])
            continue;
        for (int j=i;i*j<=n;j++)
            flag[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!flag[i])
        {
            p[++m]=i;
            l[m]=log(double(i));
        }
}
vector <ll> a;
vector <pair <ll,int> > b;
void dfs(int dep,ll x)
{
    if (dep==b.size())
    {
        a.push_back(x);
        return;
    }
    for (int i=0;i<=b[dep].second;i++)
    {
        dfs(dep+1,x);
        x*=b[dep].first;
    }
}
void prepare(ll n)
{
    b.clear();
    for (int i=1;i<=m;i++)
    {
        if (ll(p[i])*p[i]>n)
            break;
        int cnt=0;
        while (n%p[i]==0)
        {
            cnt++;
            n/=p[i];
        }
        if (cnt)
            b.push_back(make_pair(p[i],cnt));
    }
    if (n>1)
        b.push_back(make_pair(n,1));
    a.clear();
    dfs(0,1);
    sort(a.begin(),a.end());
}
bool vis[10000][50];
double f[10000][50];
int ans[10000][50];
double dp(int n,int m)
{
    if (vis[n][m])
        return(f[n][m]);
    vis[n][m]=true;
    double &ret=f[n][m];
    int &best=ans[n][m];
    ret=l[m]*(a[n]-1);
    best=power(p[m],a[n]-1);
    for (int i=1;i<n;i++)
    {
        if (a[n]%a[i]!=0)
            continue;
        double tmp=l[m]*(a[i]-1);
        if (tmp>=ret)
            break;
        int id=lower_bound(a.begin(),a.end(),a[n]/a[i])-a.begin();
        tmp+=dp(id,m+1);
        if (tmp<ret)
        {
            ret=tmp;
            best=ll(ans[id][m+1])*power(p[m],a[i]-1)%mod;
        }
    }
    return(ret);
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
        n++;
        prepare(n);
        memset(vis,0,sizeof(vis));
        dp(a.size()-1,2);
        static int id=0;
        printf("Case %d: %d\n",++id,ans[a.size()-1][2]);
    }
}

