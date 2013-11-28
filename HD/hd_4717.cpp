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
inline double sqr(double x)
{
    return(x*x);
}
point p[310],v[310];
int n;
void solve(double D,int i,int j,double &l,double &r)
{
    point V=v[i]-v[j],P=p[i]-p[j];
    double A=sqr(V.x)+sqr(V.y);
    double B=2*(P.x*V.x+P.y*V.y);
    double C=sqr(P.x)+sqr(P.y)-sqr(D);
    double delta=sqr(B)-4*A*C;
    if (delta>=0)
    {
        l=(-B-sqrt(delta))/(2*A);
        r=(-B+sqrt(delta))/(2*A);
    }
    else
        l=r=-1;
}
double calc(double D)
{
    double L=0,R=1e100;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            double l,r;
            solve(D,i,j,l,r);
            if (r<L || l>R)
                return(-1);
            L=max(L,l);
            R=min(R,r);
        }
    return(L);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            p[i].in(),v[i].in();
        double l=0,r=1e9,ans1,ans2;
        for (int lq=1;lq<=50;lq++)
        {
            double mid=(l+r)/2,t=calc(mid);
            if (t<0)
                l=mid;
            else
                r=mid,ans1=t,ans2=mid;
        }
        static int id=0;
        printf("Case #%d: %.2f %.2f\n",++id,ans1,ans2);
    }
    return(0);
}

