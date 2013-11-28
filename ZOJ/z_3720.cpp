#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define y1 __y1
#define y0 __y0
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    bool in()
    {
        return(scanf("%lf%lf",&x,&y)==2);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,b-a))==0 && sign(dot(p-a,p-b))<=0);
}
point a[30];
bool in(const point &p,int n)
{
    int res=0;
    for (int i=1;i<=n;i++)
    {
        point A=a[i-1],B=a[i];
        if (online(p,A,B))
            return(true);
        if (sign(A.y-B.y)<=0)
            swap(A,B);
        if (sign(p.y-A.y)>0)
            continue;
        if (sign(p.y-B.y)<=0)
            continue;
        res+=sign(det(B-p,A-p))>0;
    }
    return(res&1);
}
int main()
{
    point o1,o2;
    while (o1.in() && o2.in())
    {
        int n,A,B;
        scanf("%d%d%d",&n,&A,&B);
        for (int i=1;i<=n;i++)
            a[i].in();
        a[0]=a[n];
        double ans=0;
        int x0=int(ceil(o1.x)),x1=int(floor(o2.x));
        int y0=int(ceil(o1.y)),y1=int(floor(o2.y));
        for (int i=x0;i<=x1;i++)
            for (int j=y0;j<=y1;j++)
            {
                if (!in(point(i,j),n))
                    continue;
                double x=1,y=1;
                if (i==x0)
                    x-=max(0.0,o1.x-(x0-0.5));
                if (i==x1)
                    x-=max(0.0,(x1+0.5)-o2.x);
                if (j==y0)
                    y-=max(0.0,o1.y-(y0-0.5));
                if (j==y1)
                    y-=max(0.0,(y1+0.5)-o2.y);
                ans+=(A*i+B*j)*x*y;
            }
        printf("%.3f\n",ans/(o2.x-o1.x)/(o2.y-o1.y));
    }
    return(0);
}

