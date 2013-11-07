#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
    double a,r;
    scanf("%lf%lf",&a,&r);
    if (a/2>=r)
        printf("%.3f\n",pi*r*r);
    else if (sqrt(2.0)/2*a<=r)
        printf("%.3f\n",a*a);
    else
    {
        double az=2*acos(a/2/r);
        double s=pi*r*r*az/2/pi;
        double b=2*sqrt((r-a/2)*(r+a/2));
        double tmp=a/4*b;
        s-=tmp;
        s=pi*r*r-4*s;
        printf("%.3f\n",s);
    }
    return(0);
}

