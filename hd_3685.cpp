#include <cstdio>
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
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline point center(const point &a,const point &b,const point &c)
{
    return((a+b+c)/3);
}
inline point center(point *a,int n)
{
    point ret(0,0);
    double area=0;
    for (int i=1;i<=n;i++)
    {
        ret=ret+center(point(0,0),a[i-1],a[i])*det(a[i-1],a[i]);
        area+=det(a[i-1],a[i]);
    }
    if (sign(area)==0)
    {
        for (int i=0,j=1;i=j;)
            j=1;
    }
    return(ret/area);
}
inline void convex(point *a,int n,point *b,int &m)
{
    m=0;
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
    b[0]=b[--m];
}
point a[50010],b[50010];
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
        point o=center(a,n);
        int m;
        convex(a,n,b,m);
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            point p=b[i-1],q=b[i];
            ans+=sign(dot(o-p,q-p))>0 && sign(dot(o-q,p-q))>0;
        }
        printf("%d\n",ans);
    }
    return(0);
}

