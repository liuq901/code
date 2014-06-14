#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;
const double pi=acos(-1.0);
int a[110];
pair <double,double> calc(int n,double mid)
{
    double s=0,t=0;
    for (int i=1;i<=n;i++)
    {
        mid*=double(a[i])/a[i-1];
        if (mid>=1)
            return(make_pair(1e100,0));
        double tmp=mid*100/sqrt(1-mid*mid);
        s+=tmp;
        t+=sqrt(10000+tmp*tmp)/a[i];
    }
    return(make_pair(s,t));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,D;
        scanf("%d%d",&n,&D);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=a[1];
        double l=0,r=1;
        for (int T=1;T<=100;T++)
        {
            double mid=(l+r)/2;
            if (calc(n,mid).first<=D)
                l=mid;
            else
                r=mid;
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,calc(n,(l+r)/2).second);
    }
    return(0);
}

