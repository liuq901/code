#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point calc(const point &a,const point &b,double t)
{
    return(a*t+b*(1-t));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point a,b,c,d;
        a.in(),b.in(),c.in(),d.in();
        double l=0,r=1;
        for (int T=1;T<=100;T++)
        {
            double lx=(2*l+r)/3,rx=(l+2*r)/3;
            if (dist(calc(a,b,lx),calc(c,d,lx))>dist(calc(a,b,rx),calc(c,d,rx)))
                l=lx;
            else
                r=rx;
        }
        double ans=(l+r)/2;
        static int id=0;
        printf("Case %d: %.10f\n",++id,dist(calc(a,b,ans),calc(c,d,ans)));
    }
    return(0);
}

