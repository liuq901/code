#include <cstdio>
#include <cmath>
const double V=50;
struct point
{
    double x,y;
};
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
point a[110];
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    double ans=0;
    for (int i=2;i<=n;i++)
        ans+=dist(a[i-1],a[i]);
    printf("%.10f\n",ans*K/V);
    return(0);
}

