#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double convex(point a[],int n)
{
    sort(a+1,a+n+1);
    static point b[50010];
    int m=0;
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && det(b[m]-b[m-1],a[i]-b[m])<=0)
            m--;
        b[++m]=a[i];
    }
    int rev=m;
    for (int i=n-1;i;i--)
    {
        while (m>rev && det(b[m]-b[m-1],a[i]-b[m])<=0)
            m--;
        b[++m]=a[i];
    }
    double ret=0;
    for (int i=2;i<=m;i++)
        ret+=dist(b[i-1],b[i]);
    return(ret);
}
point a[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        static int id=0;
        printf("Case %d: %.10f\n",++id,convex(a,n)+2*r*pi);
    }
    return(0);
}

