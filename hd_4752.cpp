#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
};
point p[20010];
int n;
double A,B,C,L,R;
vector <double> X;
inline double sqr(double x)
{
    return(x*x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline int above(const point &p0,const point &p)
{
    double x0=p0.x,y0=p0.y,x=p.x,y=p.y;
    return(sign(y-((2*A*x0+B)*(x-x0)+y0)));
}
inline double f(double x)
{
    return(A*sqr(x)+B*x+C);
}
inline bool onPara(const point &p)
{
    return(sign(p.y-f(p.x))==0);
}
inline bool solve(double a,double b,double c,double &x1,double &x2)
{
    double delta=sqr(b)-4*a*c;
    if (sign(delta)<=0)
        return(false);
    delta=sqrt(delta);
    x1=(-b-delta)/(2*a);
    x2=(-b+delta)/(2*a);
    return(true);
}
inline void intersect(const point &a,const point &b)
{
    if (sign(a.x-b.x)==0)
    {
        double y=f(a.x);
        if (sign(y-min(a.y,b.y))>0 && sign(y-max(a.y,b.y))<0)
            X.push_back(a.x);
    }
    else
    {
        double aa=(b.y-a.y)/(b.x-a.x),bb=a.y-aa*a.x;
        double a1=A,b1=B-aa,c1=C-bb,x1,x2;
        if (solve(a1,b1,c1,x1,x2))
        {
            if (sign(x1-min(a.x,b.x))>0 && sign(x1-max(a.x,b.x))<0)
                X.push_back(x1);
            if (sign(x2-min(a.x,b.x))>0 && sign(x2-max(a.x,b.x))<0)
                X.push_back(x2);
        }
    }
}
inline double calc(double x)
{
    double t=2*A*x+B;
    return((sqrt(sqr(t)+1)*t+asinh(t))/(4*A));
}
int main()
{
    while (scanf("%d%lf%lf%lf%lf%lf",&n,&A,&B,&C,&L,&R)==6)
    {
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        if (sign(A)<0)
        {
            A*=-1,B*=-1,C*=-1;
            for (int i=1;i<=n;i++)
                p[i].y*=-1;
        }
        p[0]=p[n];
        p[n+1]=p[1];
        X.clear();
        for (int i=1;i<=n;i++)
        {
            intersect(p[i-1],p[i]);
            if (onPara(p[i]))
            {
                int u=above(p[i],p[i-1]),v=above(p[i],p[i+1]);
                if (u==1 && v<=0 || v==1 && u<=0)
                    X.push_back(p[i].x);
            }
        }
        sort(X.begin(),X.end());
        double ans=0;
        for (int i=0;i<X.size();i+=2)
        {
            if (sign(X[i]-R)>0)
                continue;
            if (sign(X[i+1]-L)<0)
                continue;
            ans+=calc(min(X[i+1],R))-calc(max(X[i],L));
        }
        printf("%.2f\n",ans);
    }
    return(0);
}

