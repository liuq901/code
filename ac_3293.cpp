#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
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
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline point incenter(const point &a,const point &b,const point &c)
{
    double A,B,C;
    A=dist(b,c),B=dist(a,c),C=dist(a,b);
    return(point((A*a.x+B*b.x+C*c.x)/(A+B+C),(A*a.y+B*b.y+C*c.y)/(A+B+C)));
}
inline double calc(const point &a,const point &b,const point &c)
{
    double a1=2*(a.x-b.x),b1=2*(a.y-b.y),c1=sqr(a.x)-sqr(b.x)+sqr(a.y)-sqr(b.y);
    double a2=2*(a.x-c.x),b2=2*(a.y-c.y),c2=sqr(a.x)-sqr(c.x)+sqr(a.y)-sqr(c.y);
    point o((c1*b2-c2*b1)/(a1*b2-a2*b1),(c1*a2-c2*a1)/(a2*b1-a1*b2));
    return(dist(a,o));
}
int main()
{
    while (1)
    {
        int x1,y1,x2,y2,x3,y3;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        if (x1==0 && y1==0 && x2==0 && y2==0 && x3==0 && y3==0)
            break;
        point a(x1,y1),b(x2,y2),c(x3,y3),o=incenter(a,b,c);
        double r;
        r=calc(b,c,o);
        point d=o+(o-a).unit()*r*2;
        r=calc(a,c,o);
        point e=o+(o-b).unit()*r*2;
        r=calc(a,b,o);
        point f=o+(o-c).unit()*r*2;
        static int id=0;
        printf("Case %d:\n%.3f %.3f\n%.3f %.3f\n%.3f %.3f\n",++id,d.x,d.y,e.x,e.y,f.x,f.y);
    }
    return(0);
}

