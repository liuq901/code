#include <cstdio>
#include <cstring>
#include <cmath>
const int n=4;
inline double sqr(double x)
{
    return(x*x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len()
    {
        return(sqrt(sqr(x)+sqr(y)));
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
inline double dist(const point &a,const point &b)
{
    return((a-b).len());
}
struct circle
{
    point o;
    double r;
    circle(){}
    circle(point o,double r):o(o),r(r){}
};
inline bool intersect(const circle &a,const circle &b,point &p1,point &p2)
{
    double l=dist(a.o,b.o);
    if (sign(fabs(a.r-b.r)-l)>0 || sign(a.r+b.r-l)<0)
        return(false);
    l=sqr(l);
    double s=((a.r-b.r)*(a.r+b.r)/l+1)/2;
    double t=sqrt(-(l-sqr(a.r-b.r))*(l-sqr(a.r+b.r))/(l*l*4));
    point dir=b.o-a.o;
    point Ndir=point(-dir.y,dir.x);
    p1=a.o+dir*s+Ndir*t;
    p2=a.o+dir*s-Ndir*t;
    return(true);
}
int a[10];
circle c[10];
bool vis[10];
bool check(int n)
{
    for (int i=1;i<n;i++)
        if (sign(dist(c[n].o,c[i].o)-c[n].r-c[i].r)<0)
            return(false);
    if (sign(dist(c[n].o,c[0].o)-(c[0].r-c[n].r))>0)
        return(false);
    return(true);
}
bool dfs(int dep)
{
    if (dep==n+1)
        return(true);
    for (int i=1;i<=n;i++)
    {
        if (vis[i])
            continue;
        vis[i]=true;
        point p[10];
        for (int j=1;j<dep;j++)
        {
            if (intersect(circle(c[0].o,c[0].r-a[i]),circle(c[j].o,c[j].r+a[i]),p[1],p[2]))
                for (int k=1;k<=2;k++)
                {
                    c[dep]=circle(p[k],a[i]);
                    if (check(dep) && dfs(dep+1))
                        return(true);
                }
            for (int k=j+1;k<dep;k++)
                if (intersect(circle(c[j].o,c[j].r+a[i]),circle(c[k].o,c[k].r+a[i]),p[1],p[2]))
                    for (int l=1;l<=2;l++)
                    {
                        c[dep]=circle(p[l],a[i]);
                        if (check(dep) && dfs(dep+1))
                            return(true);
                    }
        }
        vis[i]=false;
    }
    return(false);
}
bool check(double R)
{
    c[0]=circle(point(0,0),R);
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
    {
        vis[i]=true;
        c[i]=circle(point(R-a[i],0),a[i]);
        if (dfs(2))
            return(true);
        vis[i]=false;
    }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d",&a[1]);
        if (a[1]==0)
            break;
        for (int i=2;i<=n;i++)
            scanf("%d",&a[i]);
        double l=a[1],r=100000;
        for (int T=1;T<=100;T++)
        {
            double mid=(l+r)/2;
            if (check(mid))
                r=mid;
            else
                l=mid;
        }
        static int id=0;
        printf("Case %d: %.0f\n",++id,(l+r)/2);
    }
    return(0);
}

