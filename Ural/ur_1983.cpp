#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z=0):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
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
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline double cross(const point &a,const point &b)
{
    return(det(a,b).z);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double Acos(double x)
{
    if (sign(x+1)==0)
        return(acos(-1.0));
    if (sign(x-1)==0)
        return(acos(1.0));
    return(acos(x));
}
inline double Asin(double x)
{
    if (sign(x+1)==0)
        return(asin(-1.0));
    if (sign(x-1)==0)
        return(asin(1.0));
    return(asin(x));
}
double r;
int n;
point info[10];
double area2(point pa,point pb)
{
    if (sign(pa.len()-pb.len())<0)
        swap(pa,pb);
    if (sign(pb.len())==0)
        return(0);
    double a=pb.len();
    double b=pa.len();
    double c=(pb-pa).len();
    double cosB=dot(pb,pb-pa)/a/c;
    double B=Acos(cosB);
    double cosC=dot(pa,pb)/a/b;
    double C=Acos(cosC);
    double S;
    if (sign(a-r)>0)
    {
        S=C/2*sqr(r);
        double h=a*b*sin(C)/c;
        if (sign(h-r)<0 && sign(B-pi/2)<0)
            S-=Acos(h/r)*sqr(r)-h*Sqrt(sqr(r)-sqr(h));
    }
    else if (sign(b-r)>0)
    {
        double theta=pi-B-Asin(sin(B)/r*a);
        S=0.5*a*r*sin(theta)+(C-theta)/2*sqr(r);
    }
    else
        S=0.5*sin(C)*a*b;
    return(S);
}
double area()
{
    double S=0;
    for (int i=0;i<n;i++)
        S+=area2(info[i],info[i+1])*sign(cross(info[i],info[i+1]));
    return(fabs(S));
}
point A,B,C;
double calc()
{
    point F=det(B-A,C-A).unit();
    double t=dot(A,F),len=fabs(t);
    point o=F*t;
    if (sign(len-100)>0)
        return(0);
    point X=(B-A).unit(),Y=det(F,X).unit();
    point O=point(dot(o,X),dot(o,Y));
    info[0]=point(dot(A,X),dot(A,Y))-O;
    info[1]=point(dot(B,X),dot(B,Y))-O;
    info[2]=point(dot(C,X),dot(C,Y))-O;
    info[3]=info[0];
    n=3;
    r=Sqrt(sqr(100)-sqr(len));
    return(area());
}
int main()
{
    A.in(),B.in(),C.in();
    printf("%.10f\n",calc());
    return(0);
}

