#include <cstdio>
#include <cmath>
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool inCircle(const point &p,const point &o,double r)
{
    return(sign(dist(p,o)-r)<=0);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<=0);
}
inline point mid(const point &a,const point &b)
{
    return((a+b)/2);
}
inline point circumcenter(const point &a,const point &b,const point &c)
{
    if (online(a,b,c))
        return(mid(b,c));
    if (online(b,a,c))
        return(mid(a,c));
    if (online(c,a,b))
        return(mid(a,b));
    if (sign(dot(b-a,c-a))==0)
        return(mid(b,c));
    if (sign(dot(a-b,c-b))==0)
        return(mid(a,c));
    if (sign(dot(a-c,b-c))==0)
        return(mid(a,b));
    double A=dist(b,c),B=dist(a,c),C=dist(a,b);
    double P=(sqr(A)+sqr(B)+sqr(C))/2;
    double Q=1.0/(1/(P-sqr(A))+1/(P-sqr(B))+1/(P-sqr(C)));
    double d1=Q/(P-sqr(A)),d2=Q/(P-sqr(B)),d3=Q/(P-sqr(C));
    return(a*(1-d1)/2+b*(1-d2)/2+c*(1-d3)/2);
}
point A,B,C,P;
bool check(const point &A,const point &B,const point &C,point &O,double &r)
{
    O=mid(A,B);
    r=dist(O,A);
    return(inCircle(C,O,r));
}
void work(point &O,double &r)
{
    O=circumcenter(A,B,C);
    r=dist(O,A);
    point tmp;
    double x;
    if (check(A,B,C,tmp,x) && sign(x-r)<0)
        O=tmp,r=x;
    if (check(A,C,B,tmp,x) && sign(x-r)<0)
        O=tmp,r=x;
    if (check(B,C,A,tmp,x) && sign(x-r)<0)
        O=tmp,r=x;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        A.in(),B.in(),C.in(),P.in();
        point O;
        double r;
        work(O,r);
        static int id=0;
        printf("Case #%d: %s\n",++id,inCircle(P,O,r)?"Danger":"Safe");
    }
    return(0);
}

