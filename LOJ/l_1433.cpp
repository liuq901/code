#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    double angle() const
    {
        return(atan2(y,x));
    }
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
inline double fix(double x)
{
    while (sign(x)<0)
        x+=2*pi;
    while (sign(x-2*pi)>=0)
        x-=2*pi;
    return(sign(x-pi)<=0?x:2*pi-x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point o,a,b;
        o.in(),a.in(),b.in();
        double theta=fix((a-o).angle()-(b-o).angle());
        static int id=0;
        printf("Case %d: %.10f\n",++id,(a-o).len()*theta);
    }
    return(0);
}

