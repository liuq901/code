#include <cstdio>
int sign(double x,double eps=0)
{
    return(x<-eps?-1:x>eps);
}
double sqr(double x)
{
    return(x*x);
}
bool contain(double x1,double y1,double r1,double x2,double y2,double r2)
{
    return(sign(r1-r2)>=0 && sign(sqr(x1-x2)+sqr(y1-y2)-sqr(r1-r2))<0);
}
bool disjoint(double x1,double y1,double r1,double x2,double y2,double r2)
{
    return(sign(sqr(x1-x2)+sqr(y1-y2)-sqr(r1+r2))>0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double x1,y1,r1,x2,y2,r2;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
        if (contain(x1,y1,r1,x2,y2,r2))
            printf("2\n");
        else if (contain(x2,y2,r2,x1,y1,r1))
            printf("-2\n");
        else
            printf("%d\n",1-disjoint(x1,y1,r1,x2,y2,r2));
    }
    return(0);
}

