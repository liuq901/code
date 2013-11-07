#include <cstdio>
const double eps=1e-8;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point A,B,C,D;
        A.in(),B.in(),C.in(),D.in();
        printf("%s\n",sign(det(A-B,C-D))==0?"YES":"NO");
    }
    return(0);
}

