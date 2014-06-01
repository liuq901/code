#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
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
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double dist(const point &p,const point &a,const point &b)
{
    double rate=dot(p-a,b-a)/dot(b-a,b-a);
    if (sign(rate)>=0 && sign(rate-1)<=0)
        return(fabs(det(p-a,b-a))/dist(a,b));
    return(min(dist(p,a),dist(p,b)));
}
inline double dist(const point &a,const point &b,const point &c,const point &d)
{
    return(min(min(dist(a,c,d),dist(b,c,d)),min(dist(c,a,b),dist(d,a,b))));
}
point a[110],b[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            a[i].in();
        a[0]=a[n];
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
            b[i].in();
        b[0]=b[m];
        double ans=1e100;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                ans=min(ans,dist(a[i-1],a[i],b[j-1],b[j]));
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans/2);
    }
}

