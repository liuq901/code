#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
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
inline double area(const point &a,const point &b,const point &c)
{
    return(det(b-a,c-a));
}
inline double sqr(double x)
{
    return(x*x);
}
struct point3
{
    double x,y,z;
    point3(){}
    point3(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
};
inline point3 operator +(const point3 &a,const point3 &b)
{
    return(point3(a.x+b.x,a.y+b.y,a.z+b.z));
}
inline point3 operator -(const point3 &a,const point3 &b)
{
    return(point3(a.x-b.x,a.y-b.y,a.z-b.z));
}
inline point3 operator *(const point3 &a,double b)
{
    return(point3(a.x*b,a.y*b,a.z*b));
}
inline double dot(const point3 &a,const point3 &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point3 det(const point3 &a,const point3 &b)
{
    return(point3(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline double vlen(const point3 &a)
{
    return(sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z)));
}
struct line3
{
    point3 a,b;
    line3(){}
    line3(const point3 &a,const point3 &b):a(a),b(b){}
};
struct plane3
{
    point3 a,b,c;
    void in()
    {
        a.in();
        b.in();
        c.in();
    }
};
inline point3 pvec(const plane3 &u)
{
    return(det(u.a-u.b,u.b-u.c));
}
inline bool parallel(const plane3 &u,const plane3 &v)
{
    return(sign(vlen(det(pvec(u),pvec(v))))==0);
}
inline bool parallel(const line3 &l,const plane3 &s)
{
    return(sign(dot(l.a-l.b,pvec(s)))==0);
}
inline point3 intersect(const line3 &l,const plane3 &s)
{
    point3 ret=pvec(s);
    double t=dot(ret,s.a-l.a)/dot(ret,l.b-l.a);
    return(l.a+(l.b-l.a)*t);
}
inline line3 intersect(const plane3 &pl1,const plane3 &pl2)
{
    line3 li;
    li.a=parallel(line3(pl2.a,pl2.b),pl1)?intersect(line3(pl2.b,pl2.c),pl1):intersect(line3(pl2.a,pl2.b),pl1);
    point3 fa=det(pvec(pl1),pvec(pl2));
    li.b=li.a+fa;
    return(li);
}
inline point project(const point3 &a)
{
    return(point(a.x,a.y));
}
inline point3 toPlane(const point &p,const plane3 &u)
{
    line3 line(point3(p.x,p.y,0),point3(p.x,p.y,1));
    return(intersect(line,u));
}
plane3 red,blue;
point a[10],b[10],sol[20],tmp[20],lq[20];
int m;
void rebuild(const point &a,const point &b)
{
    sol[m]=sol[0];
    int t=0;
    for (int i=1;i<=m;i++)
    {
        double k1=area(a,b,sol[i]);
        double k2=area(a,b,sol[i-1]);
        if (sign(k1)*sign(k2)<0)
            tmp[t++]=(sol[i]*k2-sol[i-1]*k1)/(k2-k1);
        if (sign(area(a,b,sol[i]))>=0)
            tmp[t++]=sol[i];
    }
    m=t;
    for (int i=0;i<m;i++)
        sol[i]=tmp[i];
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        red.in();
        blue.in();
        a[1]=project(red.a),a[2]=project(red.b),a[3]=project(red.c);
        b[1]=project(blue.a),b[2]=project(blue.b),b[3]=project(blue.c);
        double area1=det(a[2]-a[1],a[3]-a[2]),area2=det(b[2]-b[1],b[3]-b[2]);
        if (sign(area1)==-1)
        {
            area1*=-1;
            swap(a[1],a[3]);
        }
        if (sign(area2)==-1)
        {
            area2*=-1;
            swap(b[1],b[3]);
        }
        sol[0]=point(0,0);
        sol[1]=point(100,0);
        sol[2]=point(100,100);
        sol[3]=point(0,100);
        m=4;
        a[0]=a[3],b[0]=b[3];
        for (int i=1;i<=3;i++)
        {
            rebuild(a[i-1],a[i]);
            rebuild(b[i-1],b[i]);
        }
        double area=0;
        sol[m]=sol[0];
        for (int i=0;i<m;i++)
            area+=det(sol[i],sol[i+1]);
        double ans1,ans2;
        ans1=area1-area;
        ans2=area2-area;
        if (parallel(red,blue))
        {
            point3 R=toPlane(point(0,0),red);
            point3 B=toPlane(point(0,0),blue);
            if (sign(R.z-B.z)>0)
                ans1+=area;
            else
                ans2+=area;
        }
        else
        {
            line3 line;
            line=intersect(red,blue);
            point P,Q;
            P=project(line.a);
            Q=project(line.b);
            for (int i=0;i<m;i++)
                lq[i]=sol[i];
            int temp=m;
            for (int t=0;t<=1;t++)
            {
                m=temp;
                for (int i=0;i<m;i++)
                    sol[i]=lq[i];
                rebuild(P,Q);
                double area=0;
                point O(0,0);
                sol[m]=sol[0];
                for (int i=0;i<m;i++)
                {
                    area+=det(sol[i],sol[i+1]);
                    O=O+sol[i];
                }
                O=O/m;
                point3 R=toPlane(O,red);
                point3 B=toPlane(O,blue);
                if (sign(R.z-B.z)>0)
                    ans1+=area;
                else
                    ans2+=area;
                swap(P,Q);
            }
        }
        ans1/=2,ans2/=2;
        printf("%.4f %.4f\n",ans1,ans2);
    }
    return(0);
}

