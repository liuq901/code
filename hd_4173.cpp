#include <cstdio>
#include <cmath>
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
inline int sign(double x,double eps=1e-6)
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
inline void center(const point &a,const point &b,const point &c,point &O,double &R)
{
    double A=dist(b,c),B=dist(a,c),C=dist(a,b);
    double P=(sqr(A)+sqr(B)+sqr(C))/2.0;
    double Q=1.0/(1/(P-sqr(A))+1/(P-sqr(B))+1/(P-sqr(C)));
    R=sqrt(P-Q)/2;
    double d1=Q/(P-sqr(A)),d2=Q/(P-sqr(B)),d3=Q/(P-sqr(C));
    O=(a*(1-d1)/2.0+b*(1-d2)/2.0+c*(1-d3)/2.0);
}
point a[210];
int n,ans;
void check(const point &O,double R)
{
    if (sign(R-2.5)>0)
        return;
    int now=0;
    for (int i=1;i<=n;i++)
        now+=sign(R-dist(a[i],O))>=0;
    if (now>ans)
        ans=now;
}
int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        ans=1;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                check((a[i]+a[j])/2.0,dist(a[i],a[j])/2.0);
                for (int k=j+1;k<=n;k++)
                {
                    if (sign(det(a[i]-a[k],a[j]-a[k]))==0)
                        continue;
                    point O;
                    double R;
                    center(a[i],a[j],a[k],O,R);
                    check(O,R);
                }
            }
        printf("%d\n",ans);
    }
    return(0);
}

