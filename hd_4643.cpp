#include <cstdio>
#include <cmath>
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
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
point a[60],b[60];
int n;
int belong(const point &p)
{
    int ret;
    double mi=1e100;
    for (int i=1;i<=n;i++)
    {
        double d=dist(p,b[i]);
        if (sign(d-mi)<0)
        {
            mi=d;
            ret=i;
        }
    }
    return(ret);
}
int calc(const point &P,const point &Q)
{
    int x=belong(P),y=belong(Q);
    if (x==y)
        return(0);
    if (sign(dist(P,Q))==0)
        return(1);
    point mid=(P+Q)/2;
    return(calc(P,mid)+calc(mid,Q));
}
int main()
{
    int m;
    while (scanf("%d%d",&m,&n)==2)
    {
        for (int i=1;i<=m;i++)
            a[i].in();
        for (int i=1;i<=n;i++)
            b[i].in();
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",calc(a[u],a[v]));
        }
    }
    return(0);
}

