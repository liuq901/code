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
    double angle() const
    {
        return(atan2(y,x));
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
inline void convex(point a[],int &n)
{
    sort(a+1,a+n+1);
    static point b[100010];
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
    n=m-1;
    for (int i=1;i<=n;i++)
        a[i]=b[i];
}
inline double fix(double x)
{
    while (sign(x)<0)
        x+=2*pi;
    while (sign(x)>=2*pi)
        x-=2*pi;
    return(x);
}
point a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        convex(a,n);
        double ans=1e100;
        if (n<=2)
            ans=0;
        else
        {
            a[0]=a[n];
            a[n+1]=a[1];
            for (int i=1;i<=n;i++)
                ans=min(ans,fix((a[i-1]-a[i]).angle()-(a[i+1]-a[i]).angle()));
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans/pi*180);
    }
    return(0);
}

