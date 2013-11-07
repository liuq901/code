#include <cstdio>
#include <cmath>
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    double len() const
    {
        return(sqrt(x*x+y*y+z*z));
    }
    point unit() const
    {
        double t=len();
        return(point(x/t,y/t,z/t));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
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
    return((a-b).len());
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(det(p-a,p-b).len()/dist(a,b));
}
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point reflect(const point &p,const point &a,const point &b)
{
    return(project(p,a,b)*2-p);
}
inline point intersect(const point &a,double r1,point b,double r2)
{
    double d=dist(a,b);
    double x=(sqr(r1)-sqr(r2)+sqr(d))/d/2;
    double l=Sqrt(sqr(r1)-sqr(x));
    return(a+(b-a).unit()*x+det(a,b).unit()*l);
}
point a[110];
double r[110];
int n,best,ans[110],tmp[110];
void check(const point &p)
{
    int now=0;
    point O(0,0,0);
    for (int i=1;i<=n;i++)
        if (sign(r[i]-ptoline(a[i],O,p))>=0)
            tmp[++now]=i;
    if (now>best)
    {
        best=now;
        for (int i=1;i<=best;i++)
            ans[i]=tmp[i];
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&r[i]);
        r[i]/=a[i].len();
        a[i]=a[i].unit();
    }
    for (int i=1;i<=n;i++)
    {
        check(a[i]);
        for (int j=i+1;j<=n;j++)
        {
            double d=dist(a[i],a[j]);
            if (sign(d-(r[i]+r[j]))>0 || sign(d-fabs(r[i]-r[j]))<0 || sign(dist(a[i],a[j]))==0)
                continue;
            point p=intersect(a[i],r[i],a[j],r[j]);
            check(p);
            check(reflect(p,a[i],a[j]));
        }
    }
    printf("%d\n",best);
    for (int i=1;i<=best;i++)
        printf("%d%c",ans[i],i==best?'\n':' ');
    return(0);
}

