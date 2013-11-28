#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len() const
    {
        return(sqrt(x*x+y*y));
    }
    point unit() const
    {
        double t=len();
        return(point(x/t,y/t));
    }
    point rotate() const
    {
        return(point(-y,x));
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
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(dot(p-a,p-b))<=0 && sign(det(p-a,p-b))==0);
}
inline double dist(const point &a,const point &b)
{
    return((a-b).len());
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
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,p-b))/dist(a,b));
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,d-a);
    double s2=det(d-b,c-b);
    return(a+(b-a)*s1/(s1+s2));
}
inline point intersect(const point &o,double r,const point &a,const point &b)
{
    point p=project(o,a,b);
    double d=ptoline(o,a,b);
    double l=sqrt(r*r-d*d);
    return(p+(b-a).unit()*l);
}
point a[60];
double r,R;
int n;
bool check(const point &p)
{
    double ma=0;
    for (int i=1;i<=n;i++)
        ma=max(ma,dist(p,a[i]));
    if (sign(ma-R)<=0)
    {
        printf("%.10f %.10f\n",p.x,p.y);
        return(true);
    }
    return(false);
}
bool work()
{
    a[0]=a[n];
    a[n+1]=a[1];
    for (int i=1;i<=n;i++)
    {
        point dir=(a[i-1]-a[i]).rotate().unit()*r;
        point P=a[i-1]+dir,Q=a[i]+dir;
        for (int j=1;j<=n;j++)
        {
            for (int k=j+1;k<=n;k++)
            {
                point mid=(a[j]+a[k])/2;
                point dir=(a[j]-a[k]).rotate();
                if (!parellel(Q-P,dir))
                {
                    point now=intersect(P,Q,mid,mid+dir);
                    if (online(now,P,Q) && check(now))
                        return(true);
                }
            }
            point dir=(P-Q).rotate();
            point now=intersect(P,Q,a[j],a[j]+dir);
            if (online(now,P,Q) && check(now))
                return(true);
        }
    }
    for (int i=1;i<=n;i++)
    {
        point dir1=(a[i-1]-a[i]).rotate().unit()*r;
        point dir2=(a[i]-a[i+1]).rotate().unit()*r;
        point P=a[i]+dir1,Q=a[i]+dir2;
        for (int j=1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
            {
                point mid=(a[j]+a[k])/2;
                point dir=(a[j]-a[k]).rotate();
                if (sign(ptoline(a[i],mid,mid+dir)-r)<=0)
                {
                    point now=intersect(a[i],r,mid,mid+dir);
                    if (sign(det(P-a[i],now-a[i]))>=0 && sign(det(Q-a[i],now-a[i]))<=0 && check(now))
                        return(true);
                    now=reflect(now,a[i],a[i]+dir.rotate());
                    if (sign(det(P-a[i],now-a[i]))>=0 && sign(det(Q-a[i],now-a[i]))<=0 && check(now))
                        return(true);
                }
            }
    }
    return(false);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    a[0]=a[n];
    double area=0;
    for (int i=1;i<=n;i++)
        area+=det(a[i-1],a[i]);
    if (sign(area)<0)
        reverse(a+1,a+n+1);
    scanf("%lf%lf",&r,&R);
    if (!work())
        printf("No solution\n");
    return(0);
}

