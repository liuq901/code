#include <cstdio>
#include <cmath>
const double eps=1e-8;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    void out()
    {
        printf("%.2f %.2f\n",x,y);
    }
};
point operator +(point a,point b)
{
    return(point(a.x+b.x,a.y+b.y));
}
point operator -(point a,point b)
{
    return(point(a.x-b.x,a.y-b.y));
}
point operator *(point a,double b)
{
    return(point(a.x*b,a.y*b));
}
double operator *(point a,point b)
{
    return(a.x*b.y-a.y*b.x);
}
int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
bool intersect(point a,point b,point c,point d,point &p)
{
    if (!sign((a-b)*(c-d)))
        return(false);
    double t=(a-c)*(c-d)/((a-b)*(c-d));
    p=a+(b-a)*t;
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point a,b,c,d,p;
        a.in(),b.in(),c.in(),d.in();
        if (intersect(a,b,c,d,p))
            p.out();
        else
            printf("NONE\n");
    }
    return(0);
}

