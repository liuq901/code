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
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline double sqr(double x)
{
    return(x*x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool inCircle(const point &p,const point &o,double r)
{
    return(sign(dist(p,o)-r)<0);
}
double r[1010],s[1010];
point a[1010],mass[1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            a[i].in();
            scanf("%lf",&r[i]);
        }
        int ans=-1;
        for (int i=1;i<=n;i++)
        {
            s[i]=s[i-1]+sqr(r[i]);
            mass[i]=a[i];
            if (i>1 && !inCircle(mass[i],a[i-1],r[i-1]))
            {
                ans=i;
                goto out;
            }
            for (int j=1;j<i;j++)
            {
                double V=s[i-1]-s[j-1],v=sqr(r[i]);
                mass[j]=(mass[j]*V+a[i]*v)/(V+v);
                if (j>1 && !inCircle(mass[j],a[j-1],r[j-1]))
                {
                    ans=i;
                    goto out;
                }
            }
        }
out:
        if (ans==-1)
            printf("Feasible\n");
        else
            printf("Unfeasible %d\n",ans-1);
    }
    return(0);
}

