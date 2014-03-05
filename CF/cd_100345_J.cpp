#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
FILE *in,*out;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point rotate() const
    {
        return(point(-y,x));
    }
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int sign(double x,double eps=1e-8)
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
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,b-a))/dist(a,b));
}
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline point reflect(const point &p,const point &a,const point &b)
{
    return(project(p,a,b)*2-p);
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(b-a,p-a)));
}
inline bool parellel(const point &a,const point &b,const point &c,const point &d)
{
    return(sign(det(b-a,d-c))==0);
}
inline bool touch(const point &o1,double r1,const point &o2,double r2)
{
    return(sign(dist(o1,o2)-r1-r2)==0);
}
inline point intersect(const point &o1,double r1,const point &o2,double r2)
{
    double d=dist(o1,o2);
    double x=(sqr(r1)-sqr(r2))/(2*d)+d/2;
    double l=Sqrt(sqr(r1)-sqr(x));
    point dir=(o2-o1).unit();
    return(o1+dir*x+dir.rotate()*l);
}
inline pair <point,point> intersect(const point &a,const point &b,const point &o,double r)
{
    point tmp=project(o,a,b);
    double d=dist(tmp,o);
    double l=Sqrt(sqr(r)-sqr(d));
    point dir=(b-a).unit()*l;
    return(make_pair(tmp+dir,tmp-dir));
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(b-a,c-a),s2=det(b-a,d-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline point tangent(const point &p,const point &o,double r)
{
    return(intersect((p+o)/2,dist(p,o)/2,o,r));
}
inline pair <point,point> tangent(const point &o1,double r1,const point &o2,double r2)
{
    double t=r1/(r1+r2);
    point tmp=o1+(o2-o1)*t;
    point P=tangent(tmp,o1,r1),Q=tangent(tmp,o2,r2);
    if (side(P,o1,o2)==side(Q,o1,o2))
        P=reflect(P,o1,o2);
    return(make_pair(P,Q));
}
point a[20];
double X,Y,r[20];
int n;
void get(double &u,double &v,const point &p,const point &o,double r)
{
    if (sign(dist(p,o)-r)==0)
    {
        u=atan2(o.y-p.y,o.x-p.x)-pi/2;
        v=atan2(o.y-p.y,o.x-p.x)+pi/2;
    }
    else
    {
        point P=tangent(p,o,r),Q=reflect(P,p,o);
        u=atan2(Q.y-p.y,Q.x-p.x);
        v=atan2(P.y-p.y,P.x-p.x);
    }
    if (sign(u-v)>0)
        v+=2*pi;
}
bool intersect(double x,double y,double u,double v)
{
    if (sign(y-u)<=0 || sign(v-x)<=0)
        return(false);
    return(true);
}
bool check(const point &p)
{
    if (sign(p.x)<0 || sign(p.x-X)>0 || sign(p.y)<0 || sign(p.y-Y)>0)
        return(false);
    for (int i=1;i<=n;i++)
        if (sign(dist(p,a[i])-r[i])<0)
            return(false);
    for (int i=1;i<=n;i++)
    {
        double u,v;
        get(u,v,p,a[i],r[i]);
        for (int j=i+1;j<=n;j++)
        {
            double x,y;
            get(x,y,p,a[j],r[j]);
            if (intersect(x,y,u,v) || intersect(x+2*pi,y+2*pi,u,v) || intersect(x,y,u+2*pi,v+2*pi))
                return(false);
        }
    }
    return(true);
}
int main()
{
    in=fopen("zen.in","r");
    out=fopen("zen.out","w");
    fscanf(in,"%d%lf%lf",&n,&X,&Y);
    for (int i=1;i<=n;i++)
        fscanf(in,"%lf%lf%lf",&a[i].x,&a[i].y,&r[i]);
    if (n==1)
        fprintf(out,"%.10f %.10f\n",0.0,0.0);
    else
    {
        vector <pair <point,point> > b;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (touch(a[i],r[i],a[j],r[j]))
                {
                    point p=intersect(a[i],r[i],a[j],r[j]),dir=(a[j]-a[i]).rotate();
                    b.push_back(make_pair(p+dir,p-dir));
                }
                else
                {
                    pair <point,point> tmp=tangent(a[i],r[i],a[j],r[j]);
                    b.push_back(make_pair(tmp.first,tmp.second));
                    b.push_back(make_pair(reflect(tmp.first,a[i],a[j]),reflect(tmp.second,a[i],a[j])));
                }
        for (int i=0;i<b.size();i++)
        {
            for (int j=1;j<=n;j++)
                if (sign(ptoline(a[j],b[i].first,b[i].second)-r[j])<=0)
                {
                    pair <point,point> tmp=intersect(b[i].first,b[i].second,a[j],r[j]);
                    if (check(tmp.first))
                    {
                        fprintf(out,"%.10f %.10f\n",tmp.first.x,tmp.first.y);
                        goto out;
                    }
                    if (check(tmp.second))
                    {
                        fprintf(out,"%.10f %.10f\n",tmp.second.x,tmp.second.y);
                        goto out;
                    }
                }
            for (int j=i+1;j<b.size();j++)
                if (!parellel(b[i].first,b[i].second,b[j].first,b[j].second))
                {
                    point tmp=intersect(b[i].first,b[i].second,b[j].first,b[j].second);
                    if (check(tmp))
                    {
                        fprintf(out,"%.10f %.10f\n",tmp.x,tmp.y);
                        goto out;
                    }
                }
        }
        fprintf(out,"No Zen\n");
    }
out:
    return(0);
}

