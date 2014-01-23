#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
using namespace rel_ops;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf,%lf",&x,&y);
    }
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
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline pair <point,point> intersect(const point &o1,double r1,const point &o2,double r2)
{
    double d=dist(o1,o2);
    double x=(sqr(r1)-sqr(r2))/(2*d)+d/2;
    double l=Sqrt(sqr(r1)-sqr(x));
    point dir=(o2-o1).unit();
    point p=o1+dir*x;
    return(make_pair(p+dir.rotate()*l,p-dir.rotate()*l));
}
point a[110];
int n;
int calc(const point &p)
{
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=sign(dist(p,a[i])-1)<=0;
    return(ans);
}
int calc(const point &o1,const point &o2)
{
    pair <point,point> tmp=intersect(o1,1,o2,1);
    return(max(calc(tmp.first),calc(tmp.second)));
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            a[i].in();
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
                if (sign(dist(a[i],a[j])-2)<=0 && a[i]!=a[j])
                    ans=max(ans,calc(a[i],a[j]));
            ans=max(ans,calc(a[i]));
        }
        printf("%d\n",ans);
    }
    return(0);
}

