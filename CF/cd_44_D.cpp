#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
};
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z)));
}
point a[5010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
    double ans=1e26;
    for (int i=2;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            ans=min(ans,dist(a[i],a[j])+dist(a[1],a[i])+dist(a[1],a[j]));
    printf("%.10f\n",ans/2);
    return(0);
}

