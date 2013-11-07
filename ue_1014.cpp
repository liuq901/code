#include <cstdio>
#include <cmath>
const double g=9.8;
double h,l,v;
double calc(double vx)
{
    double t=l/vx,vy=sqrt(v*v-vx*vx);
    return(vy*t-0.5*g*t*t);
}
int main()
{
    while (1)
    {
        scanf("%lf%lf%lf",&h,&l,&v);
        if (h==0 && l==0 && v==0)
            break;
        double lo=0,hi=v;
        for (int T=1;T<=100;T++)
        {
            double x1=(2*lo+hi)/3,x2=(lo+2*hi)/3;
            if (calc(x1)<=calc(x2))
                lo=x1;
            else
                hi=x2;
        }
        printf("%.2f\n",h+calc((lo+hi)/2));
    }
    return(0);
}

