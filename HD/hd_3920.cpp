#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
point a[30];
double f[1100000],d[30][30];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point p;
        scanf("%lf%lf",&p.x,&p.y);
        int n;
        scanf("%d",&n);
        n<<=1;
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                d[i][j]=dist(a[i],a[j])+min(dist(p,a[i]),dist(p,a[j]));
        int limit=1<<n;
        for (int i=0;i<limit;i++)
            f[i]=1e50;
        f[0]=0;
        for (int i=0;i<limit-1;i++)
        {
            if (f[i]>1e26)
                continue;
            int k;
            for (int j=1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                k=j;
                break;
            }
            for (int j=k+1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                double &now=f[i|1<<j-1|1<<k-1];
                now=min(now,f[i]+d[k][j]);
            }
        }
        static int id=0;
        printf("Case #%d: %.2f\n",++id,f[limit-1]);
    }
    return(0);
}

