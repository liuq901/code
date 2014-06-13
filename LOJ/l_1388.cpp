#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point unit() const
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
    }
    point rotate(double t) const
    {
        return(point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t)));
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
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double get(double a,double b,double c)
{
    return(acos((sqr(a)+sqr(b)-sqr(c))/(2*a*b)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point A,B,C,D;
        double a,b,c,d;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&b,&c,&d);
        a=dist(A,B);
        double theta=get(d,a-c,b);
        D=A+(B-A).unit().rotate(theta)*d;
        C=D+(B-A).unit()*c;
        static int id=0;
        printf("Case %d:\n%.10f %.10f %.10f %.10f\n",++id,C.x,C.y,D.x,D.y);
    }
    return(0);
}

