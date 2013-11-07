#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
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
inline double sign(double x)
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
double X[210],Y[210];
point p[210];
int work(int n,double *a,double *b,int v)
{
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        double x=a[i],y=b[i];
        int sum=0;
        for (int j=1;j<=n;j++)
            sum+=sign(x-a[j])<=0 && sign(x+v-a[j])>=0 && sign(y-b[j])==0;
        ans=max(ans,sum);
    }
    return(ans);
}
point rotate(const point &p)
{
    return(point(-p.y,p.x));
}
void get(const point &p1,const point &p2,double r,point &o1,point &o2)
{
    double len=dist(p1,p2)/2;
    double d=sqrt(sqr(r)-sqr(len));
    point p=(p1+p2)/2.0;
    o1=p+rotate(p1-p)/len*d;
    o2=p+rotate(p2-p)/len*d;
}
bool in(const point &a,const point &o,double r)
{
    return(sign(dist(a,o)-r)<=0);
}
int main()
{
    double a,b;
    while (scanf("%lf%lf",&a,&b)==2)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&X[i],&Y[i]);
        if (sign(a)==0)
            printf("%d\n",work(n,Y,X,b));
        else if (sign(b)==0)
            printf("%d\n",work(n,X,Y,a));
        else
        {
            for (int i=1;i<=n;i++)
            {
                X[i]=X[i]/a*b;
                p[i]=point(X[i],Y[i]);
            }
            int ans=1;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (i!=j && sign(dist(p[i],p[j])-2*b)<=0)
                    {
                        point o1,o2;
                        get(p[i],p[j],b,o1,o2);
                        int s1,s2;
                        s1=s2=0;
                        for (int k=1;k<=n;k++)
                        {
                            s1+=in(p[k],o1,b);
                            s2+=in(p[k],o2,b);
                        }
                        ans=max(ans,max(s1,s2));
                    }
            printf("%d\n",ans);
        }
    }
    return(0);
}

