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
    point rotate()
    {
        return(point(-y,x));
    }
    point unit()
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
    }
};
inline int sign(double x,double eps=1e-6)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline bool operator <(const point &a,const point &b)
{
    if (sign(a.x-b.x)==0)
        return(sign(a.y-b.y)==-1);
    return(sign(a.x-b.x)==-1);
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double Sqrt(double x)
{
    if (sign(x)==0)
        return(0);
    return(sqrt(x));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(Sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool intersect(const point &a,const point &b,const point &o,double r,point &cp1,point &cp2)
{
    double d=fabs(det(a-o,b-o))/dist(a,b);
    if (sign(d-r)==1)
        return(false);
    double delta=Sqrt(sqr(r)-sqr(d));
    point dir=(b-a)/dist(a,b);
    point foot=sign(det(a-o,b-o))==0?o:a+dir*dot(o-a,dir);
    cp1=foot-dir*delta;
    cp2=foot+dir*delta;
    return(true);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(a-p,b-p))==0 && sign(dot(a-p,b-p))<=0);
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d,point &p1,point &p2)
{
    double s1=det(b-a,c-a);
    double s2=det(b-a,d-a);
    if (sign(s1-s2)==0)
    {
        if (sign(s1)==0)
        {
            p1=c,p2=d;
            return(true);
        }
        return(false);
    }
    point p=(d*s1-c*s2)/(s1-s2);
    if (online(p,c,d))
    {
        p1=p2=p;
        return(true);
    }
    return(false);
}
inline bool inPolygon(const point &p,point *a,int n)
{
    int wn=0;
    for (int i=1;i<=n;i++)
    {
        if (online(p,a[i-1],a[i]))
            return(true);
        int k=sign(det(a[i-1]-p,a[i]-p));
        int d1=sign(a[i-1].y-p.y);
        int d2=sign(a[i].y-p.y);
        if (k>0 && d1<=0 && d2>0)
            wn++;
        if (k<0 && d2<=0 && d1>0)
            wn--;
    }
    return(wn!=0);
}
vector <point> b;
vector <pair <point,point> > s;
point a[30][40];
int n,cnt[30];
bool work(const point &a,const point &b,const point &c,const point &d,double R,point &P,point &Q)
{
    P=point(1e10,1e10),Q=point(-1e10,-1e10);
    point t1,t2;
    if (intersect(a,b,c,R,t1,t2))
    {
        P=min(P,min(t1,t2));
        Q=max(Q,max(t1,t2));
    }
    if (intersect(a,b,d,R,t1,t2))
    {
        P=min(P,min(t1,t2));
        Q=max(Q,max(t1,t2));
    }
    point dir=(d-c).rotate().unit()*R;
    if (intersect(a,b,c+dir,d+dir,t1,t2))
    {
        P=min(P,min(t1,t2));
        Q=max(Q,max(t1,t2));
    }
    if (intersect(a,b,c-dir,d-dir,t1,t2))
    {
        P=min(P,min(t1,t2));
        Q=max(Q,max(t1,t2));
    }
    return(P<Q);
}
bool check(double len)
{
    for (int i=2;i<=cnt[0];i++)
    {
        point X=a[0][i-1],Y=a[0][i];
        if (Y<X)
            swap(X,Y);
        s.clear();
        point u=point(1e10,1e10),v=point(-1e10,-1e10);
        for (int j=1;j<=n;j++)
        {
            b.clear();
            for (int k=1;k<=cnt[j];k++)
            {
                point P,Q;
                if (work(X,Y,a[j][k-1],a[j][k],len,P,Q))
                {
                    if (Q<X || Y<P)
                        continue;
                    s.push_back(make_pair(P,Q));
                }
                if (intersect(X,Y,a[j][k-1],a[j][k],P,Q))
                {
                    if (online(P,X,Y))
                        b.push_back(P);
                    if (online(Q,X,Y))
                        b.push_back(Q);
                }
            }
            b.push_back(X);
            b.push_back(Y);
            sort(b.begin(),b.end());
            b.erase(unique(b.begin(),b.end()),b.end());
            for (int i=1;i<b.size();i++)
                if (inPolygon((b[i-1]+b[i])/2,a[j],cnt[j]))
                    s.push_back(make_pair(b[i-1],b[i]));
        }
        for (int i=0;i<s.size();i++)
        {
            u=min(u,s[i].first);
            v=max(v,s[i].second);
        }
        if (s.empty() || X<u || v<Y)
            return(false);
        sort(s.begin(),s.end());
        point ma=s[0].second;
        for (int i=1;i<s.size();i++)
        {
            if (ma<s[i].first)
                return(false);
            ma=max(ma,s[i].second);
        }
    }
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<=n;i++)
        {
            scanf("%d",&cnt[i]);
            for (int j=1;j<=cnt[i];j++)
                scanf("%lf%lf",&a[i][j].x,&a[i][j].y);
            a[i][0]=a[i][cnt[i]];
        }
        double l=0,r=1e10;
        for (int T=1;T<=100;T++)
        {
            double mid=(l+r)/2;
            if (check(mid))
                r=mid;
            else
                l=mid;
        }
        printf("%.10f\n",(l+r)/2);
    }
    return(0);
}

