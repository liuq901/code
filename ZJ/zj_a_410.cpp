#include <cstdio>
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
int main()
{
    double a,b,c,d,e,f;
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
    if (sign(a*e-b*d)!=0)
        printf("x=%.2f\ny=%.2f\n",(c*e-b*f)/(a*e-b*d),(c*d-a*f)/(b*d-a*e));
    else if (sign(c*e-b*f)==0)
        printf("Too many\n");
    else
        printf("No answer\n");
    return(0);
}

