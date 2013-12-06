#include <cstdio>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    bool in()
    {
        return(scanf("%lf%lf",&x,&y)==2);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(double x,double eps=1e-10)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
int main()
{
    point A,B,C,D;
    while (A.in() && B.in() && C.in() && D.in())
        printf("%s\n",sign(dot(B-A,D-C))==0?"YES":"NO");
    return(0);
}

