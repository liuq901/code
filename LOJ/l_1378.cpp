#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point rotate() const
    {
        return(point(-y,x));
    }
    point unit() const
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
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
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,b-a))/dist(a,b));
}
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point reflect(const point &p,const point &a,const point &b)
{
    return(project(p,a,b)*2-p);
}
inline point get(const point &a,const point &b,double x)
{
    double y=(x-a.x)*(b.y-a.y)/(b.x-a.x)+a.y;
    return(point(x,y));
}
inline point intersect(const point &o1,double r1,const point &o2,double r2)
{
    double d=dist(o1,o2);
    double x=(sqr(r1)-sqr(r2))/(2*d)+d/2;
    double l=sqrt(sqr(r1)-sqr(x));
    point dir=(o2-o1).unit();
    return(o1+dir*x+dir.rotate()*l);
}
inline point tangent(const point &p,const point &o,double r)
{
    return(intersect((p+o)/2,dist(p,o)/2,o,r));
}
inline pair <point,point> tangent(const point &a,double r1,const point &b,double r2)
{
    if (sign(r1-r2)==0)
    {
        point dir=(b-a).rotate().unit();
        return(make_pair(a+dir*r1,b+dir*r2));
    }
    if (sign(r1-r2)>0)
    {
        pair <point,point> tmp=tangent(b,r2,a,r1);
        return(make_pair(tmp.second,tmp.first));
    }
    point p=tangent(a,b,r2-r1);
    point dir=(p-b).unit();
    return(make_pair(a+dir*r1,b+dir*r2));
}
inline double solve(const point &o1,double r1,const point &o2,double r2,const point &a,const point &b)
{
    double dis=sqrt(sqr(r1+r2)-sqr(r1-r2));
    point p=b+(a-b).unit()*dis;
    return(dist(a,p)/(2*pi*r1));
}
point a[3];
double r[3];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<3;i++)
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&r[i]);
        if (sign(a[0].x-a[1].x)>0)
        {
            swap(a[0],a[1]);
            swap(r[0],r[1]);
        }
        pair <point,point> tmp=tangent(a[0],r[0],a[1],r[1]);
        if (sign(tmp.first.y-a[0].y)>=0)
        {
            tmp.first=reflect(tmp.first,a[0],a[1]);
            tmp.second=reflect(tmp.second,a[0],a[1]);
        }
        point P=get(tmp.first,tmp.second,a[2].x);
        double len=r[2]*dist(a[2],P)/ptoline(a[2],tmp.first,tmp.second);
        point o=P+point(0,len);
        double ans=dist(a[2],o);
        point Q=o+(tmp.second-a[1]).unit()*r[2];
        if (sign(tmp.first.y-tmp.second.y)>0)
            ans+=solve(o,r[2],a[1],r[1],Q,tmp.second);
        if (sign(tmp.first.y-tmp.second.y)<0)
            ans+=solve(o,r[2],a[0],r[0],Q,tmp.first);
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}

