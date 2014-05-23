#include <cstdio>
#include <cmath>
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        double angle=acos((sqr(d)+sqr(a-c)-sqr(b))/(2*d*fabs(a-c)));
        double h=sin(angle)*d;
        static int id=0;
        printf("Case %d: %.10f\n",++id,(a+c)*h/2);
    }
    return(0);
}

