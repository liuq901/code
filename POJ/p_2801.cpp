#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    double len()
    {
        return(sqrt(x*x+y*y+z*z));
    }
    point unit()
    {
        double t=len();
        return(point(x/t,y/t,z/t));
    }
};
inline point operator -(const point &a)
{
    return(point(-a.x,-a.y,-a.z));
}
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b,a.z/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline bool online(const point &a,const point &b,const point &c)
{
    return(sign(det(a-b,b-c).len())==0);
}
inline point pvec(const point &a,const point &b,const point &c)
{
    return(det(a-b,b-c));
}
inline double dist(const point &a,const point &b)
{
    if (sign(dot(a,b)-1)==0)
        return(0);
    if (sign(dot(a,b)+1)==0)
        return(pi);
    return(acos(dot(a,b)));
}
point o,a[30];
vector <point> P;
void getmid(const point &a,const point &b)
{
    if (online(a,b,o))
    {
        P.push_back(pvec(a,b,point(20,26,2026)).unit());
        return;
    }
    point c=(a+b)/2;
    P.push_back(-c.unit());
}
void getcenter(point a,point b,point c)
{
    point v=det(b-a,c-a);
    v=v.unit();
    P.push_back(v);
    P.push_back(-v);
}
int main()
{
    int n;
    scanf("%d",&n);
    o=point(0,0,0);
    for (int i=1;i<=n;i++)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        x=x/180*pi;
        y=y/180*pi;
        a[i]=point(cos(x)*sin(y),cos(x)*cos(y),sin(x));
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            getmid(a[i],a[j]);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
                getcenter(a[i],a[j],a[k]);
    double ans=0;
    for (int i=0;i<P.size();i++)
    {
        double now=1e10;
        for (int j=1;j<=n;j++)
            now=min(now,dist(P[i],a[j]));
        ans=max(ans,now);
    }
    if (n==1)
        ans=pi;
    printf("%f\n",ans);
    return(0);
}

