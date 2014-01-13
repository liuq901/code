#include <cstdio>
#include <cmath>
double a[100000];
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
            ans+=(a[i]-ave)*(a[i]-ave);
        printf("%.10f\n",sqrt(ans/n));
    }
    return(0);
}

