#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[10],b[10];
double f[(1<<8)+10];
bool check(double mid)
{
    int limit=(1<<n)-1;
    for (int i=1;i<=limit;i++)
        f[i]=1e10;
    for (int i=1;i<=n;i++)
        f[1<<i-1]=a[i];
    for (int i=1;i<=limit;i++)
    {
        if (f[i]>1e9)
            continue;
        for (int j=1;j<=8;j++)
        {
            if (i>>j-1&1)
                continue;
            double t=f[i]+mid;
            if (t<=b[j])
                f[i|1<<j-1]=min(f[i|1<<j-1],max(double(a[j]),t));
        }
    }
    return(f[limit]<1e9);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        double l=0,r=10000;
        for (int T=1;T<=50;T++)
        {
            double mid=(l+r)/2;
            if (check(mid))
                l=mid;
            else
                r=mid;
        }
        int ans=int((l+r)*30+0.5);
        static int id=0;
        printf("Case %d: %d:%02d\n",++id,ans/60,ans%60);
    }
    return(0);
}

