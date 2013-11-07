#include <cstdio>
#include <algorithm>
using namespace std;
int a[500010],v[500010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&v[i]);
    double l=0,r=1e10,ans=-1;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2,last=-1e100;
        bool flag=false;
        for (int i=1;i<=n;i++)
            if (v[i]<0)
            {
                double now=a[i]+v[i]*mid;
                if (now<=last)
                {
                    flag=true;
                    break;
                }
            }
            else
                last=max(last,a[i]+v[i]*mid);
        if (flag)
            r=mid,ans=mid;
        else
            l=mid;
    }
    printf("%.20f\n",ans);
    return(0);
}

