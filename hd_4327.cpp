#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    point rotate() const
    {
        return(point(-y,x));
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
inline int sign(double x,double eps=1e-11)
{
    return(x<-eps?-1:x>eps);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(b-a,p-a)));
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
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
    double s1=det(c-a,b-a),s2=det(d-a,b-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,p-b))/dist(a,b));
}
inline vector <point> cut(const vector <point> &p,const point &a,const point &b)
{
    vector <point> ret;
    for (int i=1;i<p.size();i++)
    {
        point P=p[i-1],Q=p[i];
        if (side(P,a,b)>=0)
            ret.push_back(P);
        if (!parellel(Q-P,b-a))
        {
            point tmp=intersect(P,Q,a,b);
            if (sign(dot(tmp-P,tmp-Q))<0)
                ret.push_back(tmp);
        }
    }
    ret.push_back(ret[0]);
    return(ret);
}
inline double f(const point &p)
{
    return(2-p.x-p.y);
}
inline double intergrate(point a,point b,point c)
{
    if (sign(f(a)-f(b))<0)
        swap(a,b);
    if (sign(f(a)-f(c))<0)
        swap(a,c);
    double h1=f(b)-f(a),h2=f(c)-f(a),S=(h1+h2)*dist(b,c)/2;
    return(fabs(det(b-a,c-a))*f(a)/2+S*ptoline(a,b,c)/3);
}
inline double intergrate(const vector <point> &p)
{
    double ans=0;
    for (int i=3;i<p.size();i++)
        ans+=intergrate(p[1],p[i-1],p[i]);
    return(ans);
}
point a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            a[i].in();
        static int id=0;
        printf("Case #%d:\n",++id);
        for (int i=1;i<=n;i++)
        {
            vector <point> p;
            p.push_back(point(0,0));
            p.push_back(point(1,0));
            p.push_back(point(1,1));
            p.push_back(point(0,1));
            p.push_back(point(0,0));
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    continue;
                point mid=(a[i]+a[j])/2,dir=(a[j]-a[i]).rotate();
                p=cut(p,mid,mid+dir);
            }
            printf("%f\n",intergrate(p));
        }
    }
    return(0);
}

