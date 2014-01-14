#include <cstdio>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    void out() const
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
    point A,B;
    A.in(),B.in();
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point P;
        P.in();
        reflect(P,A,B).out();
    }
    return(0);
}

