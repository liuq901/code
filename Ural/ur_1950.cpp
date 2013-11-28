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
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double area(const point &a,const point &b,const point &c)
{
    return(fabs(det(b-a,c-a))/2);
}
inline bool Online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<0);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<=0);
}
inline bool on(const point &p,const point &a,const point &b,const point &c)
{
    return(online(p,a,b) || online(p,b,c) || online(p,a,c));
}
inline bool in(const point &p,const point &a,const point &b,const point &c)
{
    if (on(p,a,b,c))
        return(false);
    return(sign(area(a,b,c)-area(p,a,c)-area(p,b,c)-area(p,a,b))==0);
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,d-a),s2=det(d-b,c-b);
    if (sign(s1+s2)==0)
        return(false);
    point e=(b-a)*(s1/(s1+s2))+a;
    return(Online(e,a,b) && Online(e,c,d));
}
point P,O(0,0);
double calc(const point &A,const point &B,const point &C)
{
    if (sign(area(A,B,C))==0)
        return(0);
    if (on(P,A,B,C))
        return(area(A,B,C));
    double rate=dot(B-A,C-A)/dot(C-A,C-A);
    point Q=A+(C-A)*rate;
    if (online(P,B,Q))
        return(area(A,Q,B));
    double ans=intersect(O,P,B,Q)?area(A,Q,B):0;
    if (in(P,A,Q,B))
        return(ans+calc(A,Q,B));
    if (in(P,B,Q,C))
        return(ans+calc(B,Q,C));
    return(ans);
}
int main()
{
    scanf("%lf%lf",&P.x,&P.y);
    printf("%.10f\n",calc(point(0,0),point(10,0),point(10,10)));
    return(0);
}

