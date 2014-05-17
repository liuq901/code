#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0),eps=1e-8;
struct TC
{
    double x,y,r;
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&r);
    }
};
inline double sqr(double x)
{
    return(x*x);
}
double cirins(TC a,TC b)
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
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        TC a,b;
        a.in();
        b.in();
        static int id=0;
        printf("Case %d: %.10f\n",++id,cirins(a,b));
    }
    return(0);
}

