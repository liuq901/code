#include <cstdio>
#include <cmath>
const int N=1010;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len2()
    {
        return(x*x+y*y);
    }
    double len()
    {
        return(sqrt(len2()));
    }
    point unit()
    {
        double t=len();
        return(point(x/t,y/t));
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
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
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
point a[N],b[N];
double V[N];
double collision(int u,int v,double R)
{
    if (sign(dist(a[u],a[v])-R)<=0)
        return(0);
    point speed=b[v]*V[v]-b[u]*V[u];
    if (sign(speed.len())==0)
        return(-1);
    if (sign(dot(speed,a[u]-a[v]))<=0)
        return(-1);
    double rate=dot(a[u]-a[v],speed)/speed.len2();
    point P=a[v]+speed*rate;    
    double len=dist(a[u],P);
    if (sign(R-len)<0)
        return(-1);
    double dis=sqrt(sqr(R)-sqr(len));
    P=P-speed.unit()*dis;
    return(dist(a[v],P)/speed.len());
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        double R;
        scanf("%d%lf",&n,&R);
        for (int i=1;i<=n;i++)
        {
            double angle;
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&angle,&V[i]);
            angle=angle/180*pi;
            b[i]=point(sin(angle),cos(angle));
        }
        double ans=-1;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                double t=collision(i,j,R);
                if (sign(t)<0)
                    continue;
                if (sign(ans)<0 || sign(ans-t)>0)
                    ans=t;
            }
        if (sign(ans)<0)
            printf("No collision.\n");
        else
            printf("%.0f\n",ans);
    }
    return(0);
}

