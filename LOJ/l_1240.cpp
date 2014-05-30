#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    double len() const
    {
        return(sqrt(x*x+y*y+z*z));
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
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
inline double dist(const point &a,const point &b)
{
    return((b-a).len());
}
inline double dist(const point &p,const point &a,const point &b)
{
    double rate=dot(p-a,b-a)/dot(b-a,b-a);
    if (sign(rate)>=0 && sign(rate-1)<=0)
        return(det(p-a,b-a).len()/dist(a,b));
    return(min(dist(p,a),dist(p,b)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        point a,b,p;
        a.in(),b.in(),p.in();
        static int id=0;
        printf("Case %d: %.10f\n",++id,dist(p,a,b));
    }
    return(0);
}

