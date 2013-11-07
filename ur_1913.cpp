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
    point rotate()
    {
        return(point(-y,x));
    }
    point unit()
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
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
struct circle
{
    point o;
    double r;
    circle(const point &o,double r):o(o),r(r){}
    bool inside(const point &p) const
    {
        return(sign(dist(p,o)-sqrt(r)))<=0;
    }
    bool contain(const circle &a) const
    {
        return(sign(sqrt(a.r)+dist(o,a.o)-sqrt(r))<0);
    }
    bool disjunct(const circle &a) const
    {
        return(sign(sqrt(a.r)+sqrt(r)-dist(o,a.o))<0);
    }
};
inline bool intersect(const circle &a,const circle &b,point &A,point &B)
{
    if (a.contain(b) || b.contain(a) || a.disjunct(b))
        return(false);
    double s1=dist(a.o,b.o);
    double s2=(a.r-b.r)/s1;
    double aa=(s1+s2)/2;
    double bb=(s1-s2)/2;
    point mm=(b.o-a.o)*(aa/(aa+bb))+a.o;
    double h=sqrt(a.r-sqr(aa));
    point vv=(b.o-a.o).rotate().unit()*h;
    A=mm+vv;
    B=mm-vv;
    return(true);
}
point A,B,C;
double R;
bool calc(const circle &a,const circle &b,const circle &c,point &p)
{
    point p1,p2;
    if (!intersect(a,b,p1,p2))
        return(false);
    if (c.inside(p1))
    {
        p=p1;
        return(true);
    }
    if (c.inside(p2))
    {
        p=p2;
        return(true);
    }
    return(false);
}
bool work(const point &A,const point &B,const point &C)
{
    circle a(A,sqr(R)),b(B,sqr(R)),c(C,4*sqr(R));
    point p;
    if (!calc(a,b,c,p) && !calc(a,c,b,p) && !calc(b,c,a,p))
        return(false);
    point ans=(p+C)/2;
    printf("Now we have enough power\n");
    printf("%.10f %.10f\n%.10f %.10f\n",p.x,p.y,ans.x,ans.y);
    return(true);
}
int main()
{
    scanf("%lf",&R);
    C.in(),A.in(),B.in();
    if (sign(dist(A,C)-2*R)<=0 && sign(dist(B,C)-2*R)<=0)
    {
        printf("Now we have enough power\n");
        point p1=(A+C)/2,p2=(B+C)/2;
        printf("%.10f %.10f\n%.10f %.10f\n",p1.x,p1.y,p2.x,p2.y);
    }
    else if (!work(A,B,C) && !work(A,C,B) && !work(B,C,A))
        printf("Death\n");
    return(0);
}

