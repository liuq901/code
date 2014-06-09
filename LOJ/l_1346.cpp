#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
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
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
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
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(b-a,c-a),s2=det(b-a,d-a);
    return((c*s2-d*s1)/(s2-s1));
}
point a[20010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,x0;
        scanf("%d%d",&n,&x0);
        point o(x0,0);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        point p=a[1];
        double ans=0;
        for (int i=2;i<=n;i++)
        {
            if (sign(det(p-o,a[i]-o))<=0)
                continue;
            point tmp=intersect(o,p,a[i-1],a[i]);
            ans+=dist(tmp,a[i]);
            p=a[i];
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}

