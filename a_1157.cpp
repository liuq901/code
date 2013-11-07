#include <cstdio>
#include <cmath>
#include <complex>
#define X real()
#define Y imag()
using namespace std;
typedef complex <double> point;
typedef const point &Point;
const double eps=1e-8;
struct rect
{
    point a[5];
    void in()
    {
        double x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        a[0]=point(x1,y1);
        a[1]=point(x2,y1);
        a[2]=point(x2,y2);
        a[3]=point(x1,y2);
        a[4]=point(x1,y1);
    }
};
int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <=(Point a,Point b)
{
    return(sign(b.X-a.X)>=0 && sign(b.Y-a.Y)>=0);
}
rect a[60];
point S,T;
double h[60];
int n;
void in(point &a)
{
    scanf("%lf%lf",&a.X,&a.Y);
}
double dot(Point A,Point B)
{
    return((conj(A)*B).X);
}
double det(Point A,point B)
{
    return((conj(A)*B).Y);
}
double dist(Point A,Point B)
{
    return(abs(A-B));
}
double dist(Point P,point A,point B)
{
    if (sign(dot(P-A,B-A))<0)
        return(dist(P,A));
    if (sign(dot(P-B,A-B))<0)
        return(dist(P,B));
    return(fabs(det(A-P,B-P)/dist(A,B)));
}
double dist(Point P,const rect &a)
{
    if (a.a[0]<=P && P<=a.a[2])
        return(0);
    double ret=1e100;
    for (int i=0;i<4;i++)
        ret=min(ret,dist(P,a.a[i],a.a[i+1]));
    return(ret);
}
bool intersect(Point u1,Point u2,Point v1,Point v2)
{
    if (sign(det(u2-u1,v1-u1))*sign(det(u2-u1,v2-u1))>=0)
        return(false);
    if (sign(det(v2-v1,u1-v1))*sign(det(v2-v1,u2-v1))>=0)
        return(false);
    return(true);
}
bool check(double limit,double R)
{
    for (int i=1;i<=n;i++)
    {
        if (sign(h[i]-limit)<0)
            continue;
        if (dist(S,a[i])<R || dist(T,a[i])<R)
            return(false);
        for (int j=0;j<4;j++) 
            if (dist(a[i].a[j],S,T)<R || intersect(a[i].a[j],a[i].a[j+1],S,T))
                return(false);
    }
    return(true);
}
double sqr(double x)
{
    return(x*x);
}
bool check(double R)
{
    if (!check(R,R))
        return(false);
    for (int i=1;i<=n;i++)
        if (sign(R-h[i])>=0)
        {
            double D=R-h[i],len=sqrt(sqr(R)-sqr(D));
            if (!check(h[i],len))
                return(false);
        }
    return(true);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        in(S),in(T);
        for (int i=1;i<=n;i++)
        {
            a[i].in();
            scanf("%lf",&h[i]);
        }
        double l=0,r=1000;
        while (r-l>eps)
        {
            double mid=(l+r)/2;
            if (check(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%.8f\n",(l+r)/2);
    }
    return(0);
}

