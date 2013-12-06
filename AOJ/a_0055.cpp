#include <cstdio>
double a[20];
int main()
{
    while (scanf("%lf",&a[1])==1)
    {
        double ans=a[1];
        for (int i=2;i<=10;i++)
        {
            a[i]=i&1?a[i-1]/3:a[i-1]*2;
            ans+=a[i];
        }
        printf("%.10f\n",ans);
    }
    return(0);
}

