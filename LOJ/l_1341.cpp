#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
bool f[1000010];
int m,p[1000010];
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
}
vector <pair <ll,int> > c;
ll tmp;
int ans;
void dfs(ll now,ll limit,int pos)
{
    if (tmp/now<limit || now>=tmp/now)
        return;
    if (pos==c.size())
    {
        ans+=now>=limit;
        return;
    }
    ll tmp=1;
    for (int i=0;i<=c[pos].second;i++)
    {
        dfs(now*tmp,limit,pos+1);
        tmp*=c[pos].first;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        tmp=a;
        c.clear();
        for (int i=1;i<=m;i++)
        {
            int cnt=0;
            while (a%p[i]==0)
            {
                a/=p[i];
                cnt++;
            }
            if (cnt)
                c.push_back(make_pair(p[i],cnt));
            if (a==1)
                break;
        }
        if (a>1)
            c.push_back(make_pair(a,1));
        ans=0;
        dfs(1,b,0);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

