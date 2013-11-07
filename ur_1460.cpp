#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point rotate() const
    {
        return(point(-y,x));
    }
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
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
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double k1=det(b-a,c-a),k2=det(b-a,d-a);
    if (sign(k1-k2)==0)
        return(point(0,0));
    return((c*k2-d*k1)/(k2-k1));
}
inline point rotate(const point &a,const point &b,const point &c)
{
    point dir=(b-a).rotate();
    if (sign(det(b-a,c-a))==sign(det(b-a,dir)))
        dir=dir*-1;
    return(dir.unit());
}
inline double totlen(const point &p,const point &a,const point &b,const point &c)
{
    return(dist(p,a)+dist(p,b)+dist(p,c));
}
inline double fermat(const point &x,const point &y,const point &z,point &cp)
{
    point a[6];
    a[0]=a[3]=x;
    a[1]=a[4]=y;
    a[2]=a[5]=z;
    double len=1e100,len2;
    for (int i=0;i<3;i++)
    {
        len2=totlen(a[i],x,y,z);
        if (sign(len2-len)<0)
        {
            len=len2;
            cp=a[i];
        }
    }
    point b[3];
    for (int i=0;i<3;i++)
    {
        b[i]=rotate(a[i+1],a[i],a[i+2]);
        b[i]=(a[i+1]+a[i])/2+b[i]*dist(a[i+1],a[i])*sqrt(3.0)/2;
    }
    point cp2=intersect(b[0],a[2],b[1],a[3]);
    len2=totlen(cp2,x,y,z);
    if (sign(len2-len)<0)
    {
        len=len2;
        cp=cp2;
    }
    return(len);
}
int main()
{
    int T,N=4;
    for (scanf("%d",&T);T;T--)
    {
        point p[4];
        for (int i=0;i<N;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        point cp1,cp2;
        double len1,len2,len,ret=1e100;
        for (int i=1;i<N;i++)
        {
            cp1=(p[0]+p[i])/2;
            int j,k;
            for (j=1;j<N && i==j;j++);
            k=6-i-j;
            len2=1e100;
            while (1)
            {
                len1=fermat(cp1,p[j],p[k],cp2);
                len1=fermat(cp2,p[0],p[i],cp1);
                len=len1+dist(cp2,p[j])+dist(cp2,p[k]);
                if (sign(len-len2)<0)
                    len2=len;
                else
                    break;
            }
            ret=min(ret,len2);
        }
        printf("%.4f\n",ret);
    }
    return(0);
}

