#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double r1,r2,h,p;
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        double x=h/(r1/r2-1);
        double r=(x+p)/x*r2;
        static int id=0;
        printf("Case %d: %.10f\n",++id,pi/3*(r*r*(p+x)-r2*r2*x));
    }
    return(0);
}

