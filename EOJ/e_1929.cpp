#include <cstdio>
#include <cmath>
int main()
{
    double a,b,c;
    while (scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        double ans=log(c/a)/log(1+b/100);
        printf("%.0f\n",ceil(ans));
    }
    return(0);
}

