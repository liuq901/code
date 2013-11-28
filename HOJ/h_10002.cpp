#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
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
point operator -(point a,point b)
{
    return(point(a.x-b.x,a.y-b.y));
}
double operator *(point a,point b)
{
    return(a.x*b.y-a.y*b.x);
}
double sqr(double x)
{
    return(x*x);
}
double dist(point a,point b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
double dot(point a,point b)
{
    return(a.x*b.x+a.y*b.y);
}
double dist(point p,point a,point b)
{
    if (dot(p-a,b-a)<eps)
        return(dist(p,a));
    if (dot(p-b,a-b)<eps)
        return(dist(p,b));
    return(fabs((a-p)*(b-p))/dist(a,b));
}
point a[110];
double d[110];
int n;
double work(point P,point Q,point A,point B,point C,point D)
{
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        d[i]=min(dist(a[i],P,Q),min(min(dist(a[i],A,P),dist(a[i],B,P)),min(dist(a[i],C,Q),dist(a[i],D,Q))));
        sum+=d[i];
    }
    double ans=1e100;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            ans=min(ans,sum-d[i]-d[j]+dist(a[i],P)+dist(a[j],Q));
        }
    return(ans);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (!n)
            break;
        for (int i=1;i<=n;i++)
            a[i].in();
        if (n==1)
            printf("%.3f\n",dist(a[1],point(0.5,0.5)));
        else
        {
            double t=sqrt(3.0)/6;
            point A(0,0),B(0,1),C(1,0),D(1,1);
            printf("%.3f\n",min(work(point(t,0.5),point(1-t,0.5),A,B,C,D),work(point(0.5,t),point(0.5,1-t),A,C,B,D)));
        }
    }
    return(0);
}

