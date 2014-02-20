#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double area(point *a,int n)
{
    a[0]=a[n];
    double ret=0;
    for (int i=1;i<=n;i++)
        ret+=det(a[i-1],a[i]);
    return(fabs(ret)/2);
}
point a[100010];
int main()
{
    while (1)
    {
        double ans[2];
        for (int _=0;_<2;_++)
        {
            int n;
            scanf("%d",&n);
            if (n==0)
                goto out;
            a[1]=point(1,0);
            double now=0;
            for (int i=2;i<=n;i++)
            {
                int x;
                scanf("%d",&x);
                now+=x/180.0*pi;
                a[i]=point(cos(now),sin(now));
            }
            ans[_]=area(a,n);
        }
        int sgn=sign(ans[0]-ans[1]);
        printf("%d\n",sgn==-1?2:sgn==1?1:0);
    }
out:
    return(0);
}

