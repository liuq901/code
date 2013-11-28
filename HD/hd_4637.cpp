#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    double len() const
    {
        return(sqrt(x*x+y*y));
    }
    point unit() const
    {
        double t=len();
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
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<0);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double dist(const point &a,const point &b)
{
    return((a-b).len());
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,p-b))/dist(a,b));
}
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,b-a),s2=det(d-a,b-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline pair <point,point> intersect(const point &a,const point &b,const point &o,double r)
{
    point p=project(o,a,b);
    double d=dist(o,p),l=Sqrt(sqr(r)-sqr(d));
    point dir=(b-a).unit()*l;
    return(make_pair(p+dir,p-dir));
}
vector <pair <double,int> > a;
point V,O;
void work(const point &p,double r,double h)
{
    vector <point> lq;
    if (sign(ptoline(p,O,O+V)-r)<=0)
    {
        pair <point,point> tmp=intersect(O,O+V,p,r);
        if (sign(tmp.first.y-p.y)<=0)
            lq.push_back(tmp.first);
        if (sign(tmp.second.y-p.y)<=0)
            lq.push_back(tmp.second);
    }
    point A=p+point(0,h),B=p-point(r,0),C=p+point(r,0);
    if (!parellel(A-B,V))
    {
        point tmp=intersect(A,B,O,O+V);
        if (sign(dot(tmp-A,tmp-B))<=0)
            lq.push_back(tmp);
    }
    if (!parellel(A-C,V))
    {
        point tmp=intersect(A,C,O,O+V);
        if (sign(dot(tmp-A,tmp-C))<=0)
            lq.push_back(tmp);
    }
    sort(lq.begin(),lq.end());
    lq.erase(unique(lq.begin(),lq.end()),lq.end());
    if (lq.size()==2)
    {
        a.push_back(make_pair(dot(lq[0]-O,V)/dot(V,V),1));
        a.push_back(make_pair(dot(lq[1]-O,V)/dot(V,V),-1));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double v1,v2,v,t,x;
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v,&t,&x);
        O=point(x,0);
        V=point(-v1,v);
        int n;
        scanf("%d",&n);
        a.clear();
        for (int i=1;i<=n;i++)
        {
            double r,h;
            point p;
            scanf("%lf%lf%lf%lf",&p.x,&p.y,&r,&h);
            work(p,r,h);
        }
        double ans=0,limit=t+v1*t/(v2-v1);
        sort(a.begin(),a.end());
        int cnt=0;
        double prev;
        for (int i=0;i<a.size();i++)
            if (a[i].second==-1)
            {
                if (cnt==0)
                    prev=a[i].first;
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt==0)
                    ans+=max(min(a[i].first,limit)-max(prev,0.0),0.0);
            }
        static int id=0;
        printf("Case %d: %.4f\n",++id,ans);
    }
    return(0);
}

