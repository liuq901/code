#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    bool in()
    {
        return(scanf("%lf%lf",&x,&y)==2);
    }
    point unit() const
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
    }
    point rotate() const
    {
        return(point(-y,x));
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
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool intersect(const point &o1,double r1,const point &o2,double r2,point &P,point &Q)
{
    double d=dist(o1,o2);
    if (sign(d-(r1+r2))>0)
        return(false);
    double x=(sqr(r1)-sqr(r2))/(2*d)+d/2;
    double l=Sqrt(sqr(r1)-sqr(x));
    point dir=(o2-o1).unit();
    P=o1+dir*x-dir.rotate()*l;
    Q=o1+dir*x+dir.rotate()*l;
    return(true);
}
inline bool in(const point &p,const point &o,double r)
{
    return(sign(dist(p,o)-r)<=0);
}
inline bool on(const point &p,const point &a,const point &b,const point &O)
{
    if (p==a || p==b)
        return(true);
    if (sign(det(a-O,b-O))<0)
        return(!on(p,b,a,O));
    return(sign(det(a-O,p-O))>=0 && sign(det(b-O,p-O))<=0);
}
point o;
double R;
inline double mindist(const point &O,const point &a,const point &b)
{
    if (o==O)
        return(R);
    point tmp=O+(o-O).unit()*R;
    double ret=min(dist(o,a),dist(o,b));
    if (on(tmp,a,b,O))
        ret=min(ret,dist(o,tmp));
    return(ret);
}
point a[1010];
int n;
double calc(int id)
{
    if (n==1)
        return(max(0.0,dist(o,a[1])-R));
    if (sign(R)==0)
    {
        for (int i=1;i<=n;i++)
            if (sign(dist(a[i],a[id]))!=0)
                return(1e100);
        return(dist(o,a[id]));
    }
    point l1=a[id]-point(R,0),r1=a[id]+point(R,0),l2=r1,r2=l1;
    bool f1,f2;
    f1=f2=true;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[id])
            continue;
        point P,Q;
        if (!intersect(a[id],R,a[i],R,P,Q))
            return(1e100);
        if (f1)
        {
            if (!on(P,l1,r1,a[id]) && !on(Q,l1,r1,a[id]) && !on(l1,P,Q,a[id]) && !on(r1,P,Q,a[id]))
                f1=false;
            if (on(P,l1,r1,a[id]))
                l1=P;
            if (on(Q,l1,r1,a[id]))
                r1=Q;
            if (sign(l1.x-r1.x)>0)
                f1=false;
        }
        if (f2)
        {
            if (!on(P,l2,r2,a[id]) && !on(Q,l2,r2,a[id]) && !on(l2,P,Q,a[id]) && !on(r2,P,Q,a[id]))
                f2=false;
            if (on(P,l2,r2,a[id]))
                l2=P;
            if (on(Q,l2,r2,a[id]))
                r2=Q;
            if (sign(l2.x-r2.x)<0)
                f2=false;
        }
    }
    double ans=1e100;
    if (f1)
        ans=min(ans,mindist(a[id],l1,r1));
    if (f2)
        ans=min(ans,mindist(a[id],l2,r2));
    return(ans);
}
int main()
{
    while (o.in())
    {
        scanf("%lf%d",&R,&n);
        for (int i=1;i<=n;i++)
            a[i].in();
        double ans=1e100;
        for (int i=1;i<=n;i++)
            ans=min(ans,calc(i));
        bool flag=true;
        for (int i=1;i<=n;i++)
            if (!in(o,a[i],R))
            {
                flag=false;
                break;
            }
        if (flag)
            ans=0;
        if (ans<1e95)
            printf("%.2f\n",ans);
        else
            printf("X\n");
    }
    return(0);
}

