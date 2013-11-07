#include <cstdio>
#include <cmath>
double a[1010];
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        double ave=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
            ave+=a[i];
        }
        ave/=n;
        double ans=0;
        for (int i=1;i<=n;i++)
            ans+=sqr(a[i]-ave);
        printf("%.10f\n",sqrt(ans/n));
    }
    return(0);
}

