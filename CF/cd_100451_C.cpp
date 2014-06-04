#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    point rotate(double t) const
    {
        return(point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t)));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int W,H;
        point a,p;
        scanf("%d%d",&W,&H);
        a.in(),p.in();
        a=a-point(W/2.0,H/2.0);
        int alpha;
        double factor;
        scanf("%d%lf",&alpha,&factor);
        double theta=alpha/180.0*pi;
        point delta=p-a.rotate(theta)*factor;
        a=delta-point(W/2.0,H/2.0)*factor;
        static int id=0;
        printf(".item%d { width: %.1fpx; height: %.1fpx; left: %.1fpx; top: %.1fpx; transform: rotate(%d.0deg); }\n",++id,W*factor,H*factor,a.x,a.y,alpha);
    }
    return(0);
}

