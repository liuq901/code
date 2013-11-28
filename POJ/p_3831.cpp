#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0),eps=1e-8;
struct TC
{
    double x,y,r;
};
inline double sqr(double a)
{
    return(a*a);
}
inline double Acos(double x)
{
    if (x<-1)
        x=-1;
    if (x>1)
        x=1;
    return(acos(x));
}
double cirins(TC a,TC b)
{
    double ans=0;
    double d=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
    if (a.r<b.r)
        swap(a,b);
    if (d+eps>a.r+b.r)
        return(0);
    if (d<a.r-b.r+eps)
        return(pi*sqr(b.r));
    double a1=Acos((sqr(a.r)+d*d-sqr(b.r))/2/a.r/d);
    double a2=Acos((sqr(b.r)+d*d-sqr(a.r))/2/b.r/d);
    ans-=d*a.r*sin(a1);
    ans+=a1*sqr(a.r)+a2*sqr(b.r);
    return(ans);
}
TC a[30];
double area[30];
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
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r);
            area[i]=pi*sqr(a[i].r);
        }
        double ans=1e15;
        for (int i=1;i<=n;i++)
        {
            double l=0,r=1e15;
            a[0].x=a[i].x,a[0].y=a[i].y;
            for (int p=1;p<=100;p++)
            {
                double mid=(l+r)/2;
                a[0].r=mid;
                bool flag=true;
                for (int j=1;j<=n;j++)
                    if (cirins(a[0],a[j])<area[j]/2)
                    {
                        flag=false;
                        break;
                    }
                if (flag)
                    r=mid;
                else
                    l=mid;
            }
            ans=min(ans,(l+r)/2);
        }
        printf("%.4f\n",ans);
    }
    return(0);
}

