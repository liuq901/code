#include <cstdio>
#include <cmath>
double calc(double l,double n,double a,double m,double b,double c)
{
    double x,y;
    x=4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n);
    y=c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)-(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n);
    return(sqrt(x-y)/12);
}
int main()
{
    double OA,OB,OC,AB,AC,BC;
    scanf("%lf%lf%lf%lf%lf%lf",&OA,&OB,&OC,&AB,&AC,&BC);
    printf("%.4f\n",calc(OA,OB,OC,AB,AC,BC));
    return(0);
}

