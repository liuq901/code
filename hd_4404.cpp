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
    double len()
    {
        return(sqrt(x*x+y*y));
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
int n;
point a[110];
double r;
double area2(point pa,point pb)
{
    if (pa.len()<pb.len())
        swap(pa,pb);
    if (sign(pb.len())==0)
        return(0);
    double a=pb.len(),b=pa.len(),c=(pb-pa).len();
    double cosB=dot(pb,pb-pa)/a/c,B=acos(cosB);
    double cosC=dot(pa,pb)/a/b,C=acos(cosC);
    double S;
    if (a>r)
    {
        S=(C/2)*r*r;
        double h=a*b*sin(C)/c;
        if (h<r && B<pi/2)
            S-=acos(h/r)*r*r-h*sqrt(r*r-h*h);
    }
    else if (b>r)
    {
        double theta=pi-B-asin(sin(B)/r*a);
        S=0.5*a*r*sin(theta)+(C-theta)/2*r*r;
    }
    else
        S=0.5*sin(C)*a*b;
    return(S);
}
double area()
{
    double S=0;
    for (int i=1;i<=n;i++)
        S+=area2(a[i-1],a[i])*sign(det(a[i-1],a[i]));
    return(fabs(S));
}
int main()
{
    double x0,y0,v0,theta,t,g;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%d",&x0,&y0,&v0,&theta,&t,&g,&r,&n)==8)
    {
        theta*=pi/180;
        point o(x0+v0*t*cos(theta),y0+v0*t*sin(theta)-0.5*g*t*t);
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&a[i].x,&a[i].y);
            a[i]=a[i]-o;
        }
        a[0]=a[n];
        printf("%.2f\n",area());
    }
    return(0);
}

