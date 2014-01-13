#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
    double a,b,theta;
    scanf("%lf%lf%lf",&a,&b,&theta);
    theta*=pi/180;
    printf("%.10f\n",a*b*sin(theta)/2);
    printf("%.10f\n",a+b+sqrt(a*a+b*b-2*a*b*cos(theta)));
    printf("%.10f\n",b*sin(theta));
    return(0);
}

