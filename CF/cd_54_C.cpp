#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
double p[1010];
double calc(ll l,ll r)
{
    ll sum=0,now=1;
    if (l==1000000000000000000LL)
        return(1);
    if (r==1000000000000000000LL)
    {
        sum++;
        r--;
    }
    while (now<=r)
    {
        ll t=(now<<1)-1;
        ll begin=max(now,l),end=min(t,r);
        if (end>=begin)
            sum+=end-begin+1;
        now*=10;
    }
    return(double(sum)/(r-l+1));
}
int main()
{
    int n;
    scanf("%d",&n);
    p[0]=1;
    for (int i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        double t=calc(x,y);
        for (int j=i;j>=0;j--)
        {
            p[j]*=1-t;
            if (j!=0)
                p[j]+=p[j-1]*t;
        }
    }
    double ans=0;
    int k;
    scanf("%d",&k);
    for (int i=0;i<=n;i++)
        if (i*100>=n*k)
            ans+=p[i];
    printf("%.10f\n",ans);
    return(0);
}

