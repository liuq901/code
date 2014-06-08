#include <cstdio>
#include <cmath>
double calc(double a,double b,double c)
{
    return(acos((a*a+b*b-c*c)/(2*a*b)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double r1,r2,r3;
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        double a=calc(r1+r2,r1+r3,r2+r3);
        double b=calc(r2+r1,r2+r3,r1+r3);
        double c=calc(r3+r1,r3+r2,r1+r2);
        static int id=0;
        printf("Case %d: %.10f\n",++id,((r1+r2)*(r1+r3)*sin(a)-r1*r1*a-r2*r2*b-r3*r3*c)/2);
    }
    return(0);
}

