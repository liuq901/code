#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
int X[10010],Y[10010];
pair <int,int> a[10010];
int calc(int n)
{
    sort(a+1,a+n+1);
    int ret=1,now=a[1].first;
    for (int i=2;i<=n;i++)
        if (a[i].second>now)
        {
            ret++;
            now=a[i].first;
        }
    return(ret);
}
ll sqr(int x)
{
    return(ll(x)*x);
}
int Sqrt(ll x)
{
    int ret=max(int(sqrt(double(x))-2),0);
    while (ll(ret)*ret<=x)
        ret++;
    return(ret-1);
}
bool check(int mid,int n,int m,int D)
{
    for (int i=1;i<=n;i++)
    {
        int L=Y[i]+mid;
        if (L>D)
            return(false);
        int delta=Sqrt(sqr(D)-sqr(L));
        a[i]=make_pair(X[i]+delta,X[i]-delta);
    }
    return(calc(n)<=m);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int K,n,m,D;
        scanf("%d%d%d%d",&K,&n,&m,&D);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&X[i],&Y[i]);
            Y[i]-=K;
        }
        int l=1,r=D,ans=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid,n,m,D))
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

