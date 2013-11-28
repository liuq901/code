#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
const double eps=1e-8,pi=acos(-1.0);
struct point
{
    double x,y;
    int id;
    point(){}
    point(double x,double y,int id=0):x(x),y(y),id(id){}
    point(const point &p,int id):x(p.x),y(p.y),id(id){}
    point unit()
    {
        double t=sqrt(SQR(x)+SQR(y));
        return(point(x/t,y/t));
    }
    point rotate(double t)
    {
        return(point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t)));
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
inline double operator *(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
double r[30];
point a[30];
vector <point> poly;
void work(int x,int y)
{
    if (r[x]<r[y])
        swap(x,y);
    double D=dist(a[x],a[y]),d=r[x]-r[y],angle=acos(d/D);
    point e=(a[y]-a[x]).unit();
    poly.push_back(point(a[x]+e.rotate(angle)*r[x],x));
    poly.push_back(point(a[x]+e.rotate(-angle)*r[x],x));
    poly.push_back(point(a[y]+e.rotate(angle)*r[y],y));
    poly.push_back(point(a[y]+e.rotate(-angle)*r[y],y));
}
inline bool cmp(const point &a,const point &b)
{
    if (fabs(a.x-b.x)<eps)
        return(a.y<b.y);
    return(a.x<b.x);
}
vector <point> convex(vector <point> a)
{
    vector <point> ret;
    sort(a.begin(),a.end(),cmp);
    ret.push_back(a[0]);
    for (int i=1;i<a.size();i++)
    {
        while (ret.size()>=2)
        {
            point P=ret[ret.size()-1],Q=ret[ret.size()-2];
            if ((P-Q)*(a[i]-P)<eps)
                ret.pop_back();
            else
                break;
        }
        ret.push_back(a[i]);
    }
    int tmp=ret.size();
    for (int i=a.size()-2;i>=0;i--)
    {
        while (ret.size()>tmp)
        {
            point P=ret[ret.size()-1],Q=ret[ret.size()-2];
            if ((P-Q)*(a[i]-P)<eps)
                ret.pop_back();
            else
                break;
        }
        ret.push_back(a[i]);
    }
    return(ret);
}
double arc(const point &P,const point &Q)
{
    int id=P.id;
    double angle=atan2(P.y-a[id].y,P.x-a[id].x)-atan2(Q.y-a[id].y,Q.x-a[id].x);
    angle=fabs(angle);
    if (angle>pi)
        angle=2*pi-angle;
    return(angle*r[id]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&r[i]);
        poly.clear();
        for (int i=1;i<=n;i++)
        {
            poly.push_back(point(a[i].x-r[i],a[i].y,i));
            poly.push_back(point(a[i].x+r[i],a[i].y,i));
            poly.push_back(point(a[i].x,a[i].y-r[i],i));
            poly.push_back(point(a[i].x,a[i].y+r[i],i));
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                work(i,j);
        poly=convex(poly);
        double ans=0;
        for (int i=1;i<poly.size();i++)
        {
            point P=poly[i-1],Q=poly[i];
            if (P.id==Q.id)
                ans+=arc(P,Q);
            else
                ans+=dist(P,Q);
        }
        printf("%.10f\n",ans);
    }
    return(0);
}

