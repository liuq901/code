#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    bool in()
    {
        return(scanf("%lf%lf",&x,&y)==2);
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
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double area(const point &a,const point &b,const point &c)
{
    return(fabs(det(b-a,c-a)));
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    point tmp=a+(b-a)*t;
    if (sign(dot(tmp-a,tmp-b))<=0)
        return(dist(p,tmp));
    else
        return(min(dist(p,a),dist(p,b)));
}
inline bool in(const point &p,const point &o,double r)
{
    return(sign(dist(p,o)-r)<=0);
}
inline bool in(const point &p,const point &a,const point &b,const point &c)
{
    return(sign(area(a,b,c)-area(p,a,b)-area(p,a,c)-area(p,b,c))==0);
}
int main()
{
    point a,b,c,o;
    double r;
    while (a.in() && b.in() && c.in() && o.in())
    {
        scanf("%lf",&r);
        if (in(a,o,r) && in(b,o,r) && in(c,o,r))
            printf("b\n");
        else if (in(a,o,r) || in(b,o,r) || in(c,o,r))
            printf("c\n");
        else if (in(o,a,b,c) && sign(min(min(ptoline(o,a,b),ptoline(o,a,c)),ptoline(o,b,c))-r)>=0)
            printf("a\n");
        else if (sign(min(min(ptoline(o,a,b),ptoline(o,a,c)),ptoline(o,b,c))-r)<=0)
            printf("c\n");
        else
            printf("d\n");
    }
    return(0);
}

