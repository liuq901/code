#include <cstdio>
#include <cmath>
double eps=1e-8;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline bool sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
bool check(const point &o1,double r1,const point &o2,double r2)
{
    double len=dist(o1,o2);
    if (len<=r1-r2)
        return(true);
    return(len>=fabs(r1-r2) && len<=r1+r2);
}
int main()
{
    while (1)
    {
        double x1,y1,x2,y2,lx,ly,vd,vb,L;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&lx,&ly,&vd,&vb,&L);
        if (!sign(x1) && !sign(y1) && !sign(x2) && !sign(y2) && !sign(lx) && !sign(ly) && !sign(vd) && !sign(vb) && !sign(L))
            break;
        point p1(x2,y2),p2(x1,y1),delta(lx,ly);
        double v1=vd,v0=vb,t0=L/v0;
        double l=t0,r=1e10;
        for (int T=1;T<=100;T++)
        {
            double mid=(l+r)/2,r1=v1*(mid-t0),r2=L;
            point o1=p1,o2=p2+delta*mid;
            if (check(o1,r1,o2,r2))
                r=mid;
            else
                l=mid;
        }
        printf("%.3f %.3f\n",L,(l+r)/2);
    }
    return(0);
}

