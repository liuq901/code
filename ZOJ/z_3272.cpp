#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0),eps=1e-8;
struct circle
{
    double x,y,r;
    double area()
    {
        return(pi*r*r);
    }
};
inline double sqr(double x)
{
    return(x*x);
}
double cirins(circle a,circle b)
{
    double ans=0;
    double d=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
    if (a.r<b.r)
        swap(a,b);
    if (d+eps>a.r+b.r)
        return(0);
    if (d<a.r-b.r+eps)
        return(pi*sqr(b.r));
    double a1=acos((sqr(a.r)+sqr(d)-sqr(b.r))/2/a.r/d);
    double a2=acos((sqr(b.r)+sqr(d)-sqr(a.r))/2/b.r/d);
    ans-=d*a.r*sin(a1);
    ans+=a1*sqr(a.r)+a2*sqr(b.r);
    return(ans);
}
int n;
circle a[30];
double calc()
{
    double l=0,r=1e10;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2;
        a[0].r=mid;
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            double area=cirins(a[0],a[i]);
            if (area*2<a[i].area())
            {
                flag=false;
                break;
            }
        }
        if (flag)
            r=mid;
        else
            l=mid;
    }
    return((l+r)/2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {    
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r);
        double ans=1e10;
        for (int i=1;i<=n;i++)
        {
            a[0].x=a[i].x;
            a[0].y=a[i].y;
            ans=min(ans,calc());
        }
        printf("%.4f\n",ans);
    }
    return(0);
}

