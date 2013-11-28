#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=60;
const double pi=acos(-1.0),EPS=1e-8;
inline double sqr(double x)
{
    return(x*x);
}
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    double len()
    {
        return(sqrt(len2()));
    }
    double len2()
    {
        return(sqr(x)+sqr(y));
    }
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
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
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
struct Tcir
{
    point o;
    double r;
    Tcir(){}
    Tcir(const point &o,double r):o(o),r(r){}
    void in()
    {
        o.in();
        scanf("%lf",&r);
    }
};
inline bool operator ==(const Tcir &a,const Tcir &b)
{
    return(a.o==b.o && sign(a.r-b.r)==0);
}
inline bool overlap(const Tcir &a,const Tcir &b)
{
    return(sign((a.o-b.o).len()-(a.r-b.r))<=0);
}
struct Tevent
{
    point p;
    double ang;
    int add;
    Tevent(){}
    Tevent(const point &p,double ang,double add):p(p),ang(ang),add(add){}
};
inline bool operator <(const Tevent &a,const Tevent &b)
{
    return(a.ang<b.ang);
}
int C,E,cnt;
Tcir c[N];
double Area[N];
Tevent eve[N<<1];
void circleCrossCircle(const Tcir &a,const Tcir &b)
{
    double l=(a.o-b.o).len2(),ll=(a.o-b.o).len();
    if (sign(ll-fabs(a.r-b.r))<=0 || sign(ll-(a.r+b.r))>=0)
        return;
    double s=((a.r-b.r)*(a.r+b.r)/l+1)/2;
    double t=sqrt(-(l-sqr(a.r-b.r))*(l-sqr(a.r+b.r))/(sqr(l)*4));
    point dir=b.o-a.o,ndir=point(-dir.y,dir.x);
    point aa=a.o+dir*s+ndir*t;
    point bb=a.o+dir*s-ndir*t;
    double A=atan2(aa.y-a.o.y,aa.x-a.o.x);
    double B=atan2(bb.y-a.o.y,bb.x-a.o.x);
    eve[E++]=Tevent(bb,B,1);
    eve[E++]=Tevent(aa,A,-1);
    if (B>A)
        cnt++;
}
int main()
{
    scanf("%d",&C);
    for (int i=0;i<C;i++)
    {
        c[i].in();
        for (int j=0;j<i;j++)
            if (c[i]==c[j])
            {
                i--,C--;
                break;
            }
    }
    for (int i=0;i<C;i++)
    {
        E=0;
        cnt=1;
        for (int j=0;j<C;j++)
            if (i!=j && overlap(c[j],c[i]))
                cnt++;
        for (int j=0;j<C;j++)
            if (i!=j)
                circleCrossCircle(c[i],c[j]);
        if (E==0)
            Area[cnt]+=pi*sqr(c[i].r);
        else
        {
            sort(eve,eve+E);
            eve[E]=eve[0];
            for (int j=0;j<E;j++)
            {
                cnt+=eve[j].add;
                Area[cnt]+=det(eve[j].p,eve[j+1].p)/2;
                double theta=eve[j+1].ang-eve[j].ang;
                if (theta<0)
                    theta+=2*pi;
                Area[cnt]+=theta*sqr(c[i].r)/2-sin(theta)*sqr(c[i].r)/2;
            }
        }
    }
    printf("%.5f\n",Area[1]);
    return(0);
}

