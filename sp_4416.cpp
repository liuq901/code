#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int l[10],m[10],s[10];
struct point
{
    double x,y;
    point(double x,double y):x(x),y(y){}
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int calc(int h,int m,int s)
{
    return(h*3600+m*60+s);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
point center(int x)
{
    point P(0,0);
    for (int i=1;i<=3;i++)
    {
        double theta=2*pi*x/s[i];
        point Q=point(l[i]*sin(theta)/2,l[i]*cos(theta)/2);
        P=P+Q*m[i];
    }
    return(P/(m[1]+m[2]+m[3]));
}
int main()
{
    s[1]=43200,s[2]=3600,s[3]=60;
    while (1)
    {
        scanf("%d",&l[1]);
        if (l[1]==-1)
            break;
        scanf("%d%d%d%d%d",&l[2],&l[3],&m[1],&m[2],&m[3]);
        int b1,b2,b3,e1,e2,e3;
        scanf("%d:%d:%d %d:%d:%d",&b1,&b2,&b3,&e1,&e2,&e3);
        int begin=calc(b1,b2,b3),end=calc(e1,e2,e3);
        point now=center(begin);
        double ans=0;
        for (int i=begin+1;i<=end;i++)
        {
            point tmp=center(i);
            ans+=dist(now,tmp);
            now=tmp;
        }
        printf("%.2f\n",ans);
    }
    return(0);
}

