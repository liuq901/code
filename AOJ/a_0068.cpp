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
        scanf("%lf,%lf",&x,&y);
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
point a[110],b[100];
int convex(int n)
{
    sort(a+1,a+n+1);
    int m=0;
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && sign(det(a[i]-b[m],b[m]-b[m-1]))<=0)
            m--;
        b[++m]=a[i];
    }
    int rev=m;
    for (int i=n-1;i;i--)
    {
        while (m>rev && sign(det(a[i]-b[m],b[m]-b[m-1]))<=0)
            m--;
        b[++m]=a[i];
    }
    return(m-1);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            a[i].in();
        printf("%d\n",n-convex(n));
    }
    return(0);
}

