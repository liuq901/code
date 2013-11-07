#include <cstdio>
#include <cmath>
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    double a,b;
    scanf("%lf%lf",&a,&b);
    printf("%.10f\n",(sqr(a)+sqr(b))/4+sqrt(2.0)*a*b/2);
    return(0);
}

