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
int w;
bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    return(det(c-a,b-a)*det(d-a,b-a)<0 && det(a-d,c-d)*det(b-d,c-d)<0);
}
double sqr(double x)
{
    return(x*x);
}
double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
double dist(const point &p,const point &a,const point &b)
{
    if (dot(p-a,b-a)<0)
        return(dist(p,a));
    if (dot(p-b,a-b)<0)
        return(dist(p,b));
    return(fabs(det(p-a,b-a))/dist(a,b));
}
struct polygon
{
    int n;
    point a[30];
    void in()
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            a[i].in();
        a[0]=a[n];
    }
    bool tolower(double r)
    {
        for (int i=1;i<=n;i++)
            if (a[i].y-2*r<=-w)
                return(true);
        return(false);
    }
    bool toupper(double r)
    {
        for (int i=1;i<=n;i++)
            if (a[i].y+2*r>=w)
                return(true);
        return(false);
    }
    bool touch(const polygon &b,double r)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=b.n;j++)
            {
                if (intersect(a[i],a[i-1],b.a[j],b.a[j-1]))
                    return(true);
                if (dist(a[i],b.a[j],b.a[j-1])<=2*r)
                    return(true);
            }
        return(false);
    }
};
polygon p[110];
int n,f[110];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
bool merge(int x,int y)
{
    f[find(x)]=find(y);
    return(find(0)==find(n+1));
}
bool check(double r)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=p[i].n;j++)
           if (dist(point(0,0),p[i].a[j-1],p[i].a[j])<=r)
               return(false);
    for (int i=0;i<=n+1;i++)
        f[i]=i;
    for (int i=1;i<=n;i++)
    {
        if (p[i].tolower(r) && merge(0,i))
            return(false);
        if (p[i].toupper(r) && merge(n+1,i))
            return(false);
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (p[i].touch(p[j],r) && merge(i,j))
                return(false);
    return(true);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&w,&n);
        if (w==0 && n==0)
            break;
        for (int i=1;i<=n;i++)
            p[i].in();
        w>>=1;
        double l=0,r=w;
        for (int T=1;T<=26;T++)
        {
            double mid=(l+r)/2;
            if (check(mid))
                l=mid;
            else
                r=mid;
        }
        if (fabs(l)<1e-8)
            printf("impossible\n");
        else
            printf("%.2f\n",l);
    }
    return(0);
}

