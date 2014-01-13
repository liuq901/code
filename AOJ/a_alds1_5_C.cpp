#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(double x,double y):x(x),y(y){}
    point rotate() const
    {
        double t=pi/3;
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
void calc(const point &a,const point &b,int dep)
{
    if (dep==0)
    {
        printf("%.10f %.10f\n",a.x,a.y);
        return;
    }
    point p=a+(b-a)/3;
    point q=b+(a-b)/3;
    point o=p+(q-p).rotate();
    calc(a,p,dep-1);
    calc(p,o,dep-1);
    calc(o,q,dep-1);
    calc(q,b,dep-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    calc(point(0,0),point(100,0),n);
    printf("%.10f %.10f\n",100.0,0.0);
    return(0);
}

