#include <cstdio>
#include <cmath>
const double eps=1e-8;
inline double sqr(double x)
{
    return(x*x);
}
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    double mod()
    {
        return(sqrt(sqr(x)+sqr(y)+sqr(z)));
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
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z)));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
point a[510],v[510];
bool crash(int x,int y,double R,double &T)
{
    point V=v[x]-v[y];
    if (sign(V.mod())==0)
        return(false);
    double t=dot(a[y]-a[x],V)/dot(V,V);
    point P=a[x]+V*t;
    double D=dist(a[y],P);
    if (sign(D-R)==1 || sign(dot(P-a[x],V))==-1)
        return(false);
    double len=dist(a[x],P)-sqrt(sqr(R)-sqr(D));
    T=len/V.mod();
    return(true);
}
int main()
{
    int n;
    double D;
    scanf("%d%lf",&n,&D);
    for (int i=1;i<=n;i++)
    {
        a[i].in();
        v[i].in();
    }
    bool flag=true;
    double t;
    int x,y;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            double now;
            if (crash(i,j,D,now) && (flag || now<t))
            {
                flag=false;
                t=now;
                x=i;
                y=j;
            }
        }
    if (flag)
        printf("OK\n");
    else
    {
        printf("ALARM!\n");
        printf("%.3f %d %d\n",t,x,y);
    }
    return(0);
}

