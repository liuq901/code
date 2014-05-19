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
    double len() const
    {
        return(sqrt(x*x+y*y));
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
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
inline double Asin(double x)
{
    if (sign(x-1)==0)
        return(asin(1.0));
    if (sign(x+1)==0)
        return(asin(-1.0));
    return(asin(x));
}
inline double Acos(double x)
{
    if (sign(x-1)==0)
        return(acos(1.0));
    if (sign(x+1)==0)
        return(acos(-1.0));
    return(acos(x));
}
point info[5];
double r;
double area(point pa,point pb)
{
    if (sign(pa.len()-pb.len())<0)
        swap(pa,pb);
    if (sign(pb.len())==0)
        return(0);
    double a=pb.len();
    double b=pa.len();
    double c=(pb-pa).len();
    double cosB=dot(pb,pb-pa)/a/c;
    double B=acos(cosB);
    double cosC=dot(pa,pb)/a/b;
    double C=acos(cosC);
    double S;
    if (sign(a-r)>0)
    {
        S=(C/2)*r*r;
        double h=a*b*sin(C)/c;
        if (sign(h-r)<0 && sign(B-pi/2)<0)
            S-=Acos(h/r)*r*r-h*Sqrt(r*r-h*h);
    }
    else if (sign(b-r)>0)
    {
        double theta=pi-B-Asin(sin(B)/r*a);
        S=a*r*sin(theta)/2+(C-theta)/2*r*r;
    }
    else
        S=sin(C)*a*b/2;
    return(S);
}
double area()
{
    double S=0;
    for (int i=0;i<4;i++)
        S+=area(info[i],info[i+1])*sign(det(info[i],info[i+1]));
    return(fabs(S));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double x0,y0,x1,y1,x2,y2;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&x0,&y0,&r,&x1,&y1,&x2,&y2);
        x1-=x0,y1-=y0;
        x2-=x0,y2-=y0;
        info[0]=point(x1,y1);
        info[1]=point(x2,y1);
        info[2]=point(x2,y2);
        info[3]=point(x1,y2);
        info[4]=info[0];
        static int id=0;
        printf("Case %d: %.10f\n",++id,area());
    }
    return(0);
}

