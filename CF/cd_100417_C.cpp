#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
int a[110],b[110];
bool check(int m,int n,int p,ll mid)
{
    multiset <ll> S;
    for (int i=1;i<=m;i++)
    {
        ll now=mid;
        for (int j=1;j<=n;j++)
        {
            now-=a[i];
            S.insert(now);
        }
    }
    for (int i=1;i<=n;i++)
    {
        multiset <ll>::iterator k=S.lower_bound(b[i]);
        if (k==S.end())
            return(false);
        S.erase(k);
    }
    return(true);
}
int main()
{
    freopen("budget.in","r",stdin);
    freopen("budget.out","w",stdout);
    int m,n,p;
    scanf("%d%d%d",&m,&n,&p);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        a[i]=(p+a[i]-1)/a[i];
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    ll l=0,r=1LL<<60,ans=-1;
    while (l<=r)
    {
        ll mid=l+r>>1;
        if (check(m,n,p,mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    printf("%I64d\n",ans-1);
    return(0);
}

