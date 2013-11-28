#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
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
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
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
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,p-b))/dist(a,b));
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<=0);
}
inline double Sqrt(double x)
{
    if (sign(x)<=0)
        return(0);
    return(sqrt(x));
}
inline bool intersect(const point &A,const point &B,const point &O,double r,point &P,point &Q)
{
    double d=ptoline(O,A,B);
    if (sign(d-r)>0)
        return(false);
    double l=Sqrt(sqr(r)-sqr(d));
    double rate=dot(O-A,B-A)/dot(B-A,B-A);
    point mid=A+(B-A)*rate;
    P=mid+(B-A).unit()*l;
    Q=mid-(B-A).unit()*l;
    return(true);
}
int n;
point O(0,0);
double r,X1[60],X2[60],Y1[60],Y2[60];
vector <double> b;
vector <pair <double,double> > V;
void calc(const point &A,const point &B)
{
    point P,Q;
    if (intersect(A,B,O,r,P,Q))
    {
        if (online(P,A,B))
            b.push_back(atan2(P.y,P.x));
        if (online(Q,A,B))
            b.push_back(atan2(Q.y,Q.x));
    }
}
inline void work(int id)
{
    if (sign(X1[id]-X2[id])==0 || sign(Y1[id]-Y2[id])==0)
        return;
    point A(X1[id],Y1[id]),B(X1[id],Y2[id]),C(X2[id],Y1[id]),D(X2[id],Y2[id]);
    b.clear();
    calc(A,B);
    calc(A,C);
    calc(B,D);
    calc(C,D);
    b.push_back(pi);
    b.push_back(-pi);
    b.push_back(pi/2);
    b.push_back(-pi/2);
    b.push_back(0);
    sort(b.begin(),b.end());
    for (int i=1;i<b.size();i++)
    {
        double angle=(b[i-1]+b[i])/2;
        point mid=point(cos(angle),sin(angle))*r;
        if (sign(mid.x-X1[id])>=0 && sign(X2[id]-mid.x)>=0 && sign(mid.y-Y1[id])>=0 && sign(Y2[id]-mid.y)>=0)
            V.push_back(make_pair(b[i-1],b[i]));
    }
}
int main()
{
    while (scanf("%lf%d",&r,&n)==2)
    {
        for (int i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&X1[i],&Y1[i],&X2[i],&Y2[i]);
        V.clear();
        for (int i=1;i<=n;i++)
            work(i);
        sort(V.begin(),V.end());
        double ans=0;
        if (!V.empty())
        {
            double left=V[0].first,right=V[0].second;
            for (int i=1;i<V.size();i++)
            {
                if (sign(V[i].first-right)>0)
                {
                    ans+=(right-left)*r;
                    left=V[i].first,right=V[i].second;
                }
                right=max(right,V[i].second);
            }
            ans+=(right-left)*r;
        }
        printf("%.3f\n",ans);
    }
    return(0);
}

