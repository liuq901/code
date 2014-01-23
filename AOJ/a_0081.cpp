#include <cstdio>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void out()
    {
        printf("%.10f %.10f\n",x,y);
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
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point reflect(const point &p,const point &a,const point &b)
{
    return(project(p,a,b)*2-p);
}
int main()
{
    point a,b,p;
    while (scanf("%lf,%lf,%lf,%lf,%lf,%lf",&a.x,&a.y,&b.x,&b.y,&p.x,&p.y)==6)
        reflect(p,a,b).out();
    return(0);
}

