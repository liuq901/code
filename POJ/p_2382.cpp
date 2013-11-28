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
};
struct Tcir
{
    point o;
    double r;
    Tcir(){}
    Tcir(const point &o,double r):o(o),r(r){}
};
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
double calc(Tcir a,Tcir b)
{
    double ans=0,d=dist(a.o,b.o);
    if (sign(a.r-b.r)<0)
        swap(a,b);
    if (sign(d-(a.r+b.r))>=0)
        return(0);
    if (sign(d-(a.r-b.r))<=0)
        return(pi*sqr(b.r));
    double a1=acos((sqr(a.r)+sqr(d)-sqr(b.r))/2/a.r/d);
    double a2=acos((sqr(b.r)+sqr(d)-sqr(a.r))/2/b.r/d);
    ans-=d*a.r*sin(a1);
    ans+=a1*sqr(a.r)+a2*sqr(b.r);
    return(ans);
}
Tcir c[20];
int main()
{
    int n;
    double x0,y0,R;
    scanf("%d%lf%lf%lf",&n,&x0,&y0,&R);
    c[0]=Tcir(point(x0,y0),R);
    for (int i=1;i<=n;i++)
    {
        double x,y,R;
        scanf("%lf%lf%lf",&x,&y,&R);
        c[i]=Tcir(point(x,y),R);
    }
    double ans=0;
    for (int i=0;i<1<<n;i++)
    {
        bool flag=true;
        for (int j=1;j<=n;j++)
            if (i>>j-1&1)
                for (int k=j+1;k<=n;k++)
                    if (i>>k-1&1)
                        if (sign(dist(c[j].o,c[k].o)-(c[j].r+c[k].r))<0)
                        {
                            flag=false;
                            goto out;
                        }
out:
        if (flag)
        {
            double now=pi*sqr(c[0].r);
            for (int j=1;j<=n;j++)
                if (i>>j-1&1)
                    now+=pi*sqr(c[j].r)-calc(c[0],c[j]);
            ans=max(ans,now);
        }
    }
    printf("%.4f\n",ans);
    return(0);
}

