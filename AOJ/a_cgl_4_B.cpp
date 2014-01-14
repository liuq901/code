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
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<0);
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
inline int convex(point *a,int n)
{
    static point b[100010];
    int m=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    int limit=m;
    for (int i=n-1;i;i--)
    {
        while (m>limit && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    for (int i=1;i<m;i++)
        a[i]=b[i];
    return(m-1);
}
point a[160010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i].in();
    n=convex(a,n);
    for (int i=1;i<=n;i++)
        a[n+i]=a[i];
    int now=2;
    double ans=0;
    for (int i=1;i<=n;i++)
    {
        while (now<2*n && sign(det(a[i+1]-a[i],a[now+1]-a[now]))>0)
            now++;
        ans=max(ans,max(dist(a[i],a[now]),dist(a[i+1],a[now])));
    }
    printf("%.10f\n",ans);
    return(0);
}

