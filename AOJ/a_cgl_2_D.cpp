#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
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
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
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
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,b-a),s2=det(d-a,b-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double dist(const point &p,const point &a,const point &b)
{
    point q=project(p,a,b);
    if (sign(dot(q-a,q-b))<=0)
        return(dist(p,q));
    return(min(dist(p,a),dist(p,b)));
}
inline double dist(const point &a,const point &b,const point &c,const point &d)
{
    if (sign(det(b-a,d-c))!=0)
    {
        point p=intersect(a,b,c,d);
        if (sign(dot(p-a,p-b))<=0 && sign(dot(p-c,p-d))<=0)
            return(0);
    }
    return(min(min(dist(a,c,d),dist(b,c,d)),min(dist(c,a,b),dist(d,a,b))));
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point a,b,c,d;
        a.in(),b.in(),c.in(),d.in();
        printf("%.10f\n",dist(a,b,c,d));
    }
    return(0);
}

