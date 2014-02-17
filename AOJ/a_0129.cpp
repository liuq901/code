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
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(dot(p-a,p-b))<=0);
}
inline bool check(const point &p,const point &q,const point &o,double r)
{
    point tmp=project(o,p,q);
    double d=dist(o,tmp);
    if (sign(d-r)>0)
        return(false);
    double l=Sqrt(sqr(r)-sqr(d));
    point dir=(p-q).unit();
    return(online(tmp+dir*l,p,q) || online(tmp-dir*l,p,q));
}
point o[110];
double r[110];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%lf%lf%lf",&o[i].x,&o[i].y,&r[i]);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            point p,q;
            scanf("%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y);
            bool flag=false;
            for (int i=1;i<=n;i++)
                if (check(p,q,o[i],r[i]))
                {
                    flag=true;
                    break;
                }
            printf("%s\n",flag?"Safe":"Danger");
        }
    }
    return(0);
}

