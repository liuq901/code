#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    int x,y,id;
    double angle,dis;
};
inline double sign(double x,double eps=1e-10)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.angle-b.angle)<0 || sign(a.angle-b.angle)==0 && sign(a.dis-b.dis)<0);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
point a[2010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].id=i-1;
        }
        for (int i=1;i<=n;i++)
            if (a[i].x<a[1].x || a[i].x==a[1].x && a[i].y<a[1].y)
                swap(a[1],a[i]);
        for (int i=2;i<=n;i++)
        {
            a[i].angle=atan2(a[i].y-a[1].y,a[i].x-a[1].x);
            a[i].dis=dist(a[1],a[i]);
        }
        sort(a+2,a+n+1);
        static int id=0;
        printf("Case %d:\n",++id);
        if (sign(a[2].angle-a[n].angle)==0)
            printf("Impossible\n");
        else
        {
            int k;
            for (int i=n;i;i--)
                if (sign(a[i].angle-a[n].angle)==0)
                    k=i;
            reverse(a+k,a+n+1);
            for (int i=1;i<=n;i++)
                printf("%d%c",a[i].id,i==n?'\n':' ');
        }
    }
    return(0);
}

