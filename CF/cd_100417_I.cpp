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
    point unit() const
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
    }
    double angle() const
    {
        return(atan2(y,x));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
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
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,b-a))/dist(a,b));
}
inline point half(const point &p,const point &a,const point &b)
{
    point u=p+(a-p).unit();
    point v=p+(b-p).unit();
    return((u+v)/2);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(b-a,c-a),s2=det(b-a,d-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline void convex(int &n,point a[])
{
    point b[110];
    int m=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    int rev=m;
    for (int i=n-1;i;i--)
    {
        while (m>rev && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    n=m-1;
    for (int i=1;i<=n;i++)
        a[i]=b[i];
}
inline double move(int n,point a[],double len)
{
    double ret=0;
    a[0]=a[n];
    a[n+1]=a[1];
    point b[110];
    for (int i=1;i<=n;i++)
    {
        point dir=(half(a[i],a[i-1],a[i+1])-a[i]).unit();
        double theta=dir.angle()-(a[i+1]-a[i]).angle();
        double dis=len/sin(theta);
        ret+=dis;
        b[i]=a[i]+dir*dis;
    }
    for (int i=1;i<=n;i++)
        a[i]=b[i];
    return(ret);
}
point a[110];
int main()
{
    freopen("roof.in","r",stdin);
    freopen("roof.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    double ans=0;
    while (1)
    {
        convex(n,a);
        if (n<=2)
        {
            if (n==2)
                ans+=dist(a[1],a[2]);
            break;
        }
        a[0]=a[n];
        a[n+1]=a[1];
        a[n+2]=a[2];
        double len=1e100;
        for (int i=1;i<=n;i++)
        {
            point p=half(a[i],a[i-1],a[i+1]);
            point q=half(a[i+1],a[i],a[i+2]);
            point tmp=intersect(a[i],p,a[i+1],q);
            len=min(len,ptoline(tmp,a[i],a[i+1]));
            len=min(len,ptoline(tmp,a[i-1],a[i]));
            len=min(len,ptoline(tmp,a[i+1],a[i+2]));
        }
        ans+=move(n,a,len);
    }
    printf("%.10f\n",ans);
    return(0);
}

