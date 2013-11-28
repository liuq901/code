#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-3,pi=acos(-1.0);
const int m=50;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    bool in(double X,double Y) const
    {
        return(x>=0 && x<=X && y>=0 && y<=Y);
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
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
int X,Y,n;
point a[m+10],p[1010];
double d[m+10];
double ran()
{
    return(rand()%10001/10000.0);
}
double calc(const point &P)
{
    double ret=1e100;
    for (int i=1;i<=n;i++)
        ret=min(ret,dist(P,p[i]));
    return(ret);
}
point work()
{
    for (int i=1;i<=m;i++)
    {
        a[i]=point(ran()*X,ran()*Y);
        d[i]=calc(a[i]);
    }
    double rate=min(X,Y);
    while (rate>eps)
    {
        for (int i=1;i<=m;i++)
        {
            double angle=ran()*2*pi;
            point tmp=a[i]+point(sin(angle),cos(angle))*rate;
            if (tmp.x<0)
                tmp.x=0;
            if (tmp.x>X)
                tmp.x=X;
            if (tmp.y<0)
                tmp.y=0;
            if (tmp.y>Y)
                tmp.y=Y;
            double now=calc(tmp);
            if (now>d[i])
                d[i]=now,a[i]=tmp;
        }
        rate*=0.8;
    }
    int k=1;
    for (int i=1;i<=m;i++)
        if (d[i]>d[k])
            k=i;
    return(a[k]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&X,&Y,&n);
        for (int i=1;i<=n;i++)
            p[i].in();
        point ans=work();
        printf("The safest point is (%.1f, %.1f).\n",ans.x,ans.y);
    }
    return(0);
}

