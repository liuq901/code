#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
double L,r;
double sqr(double x)
{
    return(x*x);
}
double f(double x)
{
    double h=sqrt(sqr(L)-sqr(x));
    return((3*sqr(r)+3*r*x+sqr(x))*h);
}
int main()
{
    freopen("frustum.in","r",stdin);
    freopen("frustum.out","w",stdout);
    scanf("%lf%lf",&L,&r);
    r/=2;
    double l=0,r=L;
    for (int T=1;T<=10000;T++)
    {
        double lx=(2*l+r)/3,rx=(l+2*r)/3;
        if (f(lx)<f(rx))
            l=lx;
        else
            r=rx;
    }
    printf("%.15f\n",pi/3*f((l+r)/2));
    return(0);
}

