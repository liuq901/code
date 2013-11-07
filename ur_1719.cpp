#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
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
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(b-a,p-a)));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline point find(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point get(const point &p,const point &a,const point &b)
{
    point q=find(p,a,b);
    return(q*2-p);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,d-a);
    double s2=det(d-b,c-b);
    return((b-a)*(s1/(s1+s2))+a);
}
const point O(0,0);
double calc(const point &P,const point &A,const point &B,const point &C,const point &D)
{
    double ret=1e26;
    if (sign(det(B-A,D-C))!=0)
    {
        point Q=intersect(A,B,C,D);
        ret=dist(P,Q);
    }
    point Q=find(P,C,D);
    if (side(P,A,B)*side(Q,A,B)!=1)
        ret=min(ret,dist(P,Q));
    return(ret);
}
double work2(const point &A,const point &B,const point &C,const point &D)
{
    return(min(calc(O,A,B,C,D),calc(get(O,A,B),A,B,C,D)));
}
double work1(const point &A,const point &B,const point &C,const point &D)
{
    return(min(work2(A,B,C,D),work2(C,D,A,B)));
}
int main()
{
    point A,B,C,D;
    A.in(),B.in(),C.in(),D.in();
    double ans=min(min(work1(A,B,C,D),work1(A,C,B,D)),work1(A,D,B,C));
    printf("%.10f\n",ans);
    return(0);
}

