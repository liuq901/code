#include <cstdio>
#include <cmath>
#define SQR(x) ((x)*(x))
double h1,h2,d1,d2,a,b;
bool check(double x)
{
    if (x<0)
        return(false);
    double y=(d2-x/sqrt(a))*sqrt(b);
    if (y<0)
        return(false);
    x*=x,y*=y;
    double X=sqrt(x/a);
    if (d1<=X)
    {
        double h=h1-a*SQR(d1);
        return(h>=h2);
    }
    else
    {
        double h=y-b*SQR(d1-X);
        return(h>=h2);
    }
}
int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf",&h1,&h2,&d1,&d2,&a,&b)==6)
    {
        double A,B,C,delta;
        A=1+b/a;
        B=-2*b*d2/sqrt(a);
        C=b*d2*d2-h1;
        delta=SQR(B)-4*A*C;
        if (delta<0)
            printf("No\n");
        else
        {
            double x1,x2;
            x1=(-B+sqrt(delta))/(2*A);
            x2=(-B-sqrt(delta))/(2*A);
            printf("%s\n",check(x1) || check(x2)?"Yes":"No");
        }
    }
    return(0);
}

