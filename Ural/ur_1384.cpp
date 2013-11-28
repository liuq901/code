#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
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
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(dot(p-a,p-b))<=0 && sign(det(p-a,p-b))==0);
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
}
inline double ptoline(const point &p,const point &a,const point &b)
{
    return(fabs(det(p-a,p-b))/dist(a,b));
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,d-a);
    double s2=det(d-b,c-b);
    return(a+(b-a)*(s1/(s1+s2)));
}
inline point incenter(const point &a,const point &b,const point &c)
{
    double A=dist(b,c),B=dist(a,c),C=dist(a,b);
    if (sign(A+B+C)==0)
        return(a);
    return((a*A+b*B+c*C)/(A+B+C));
}
inline point circumcenter(const point &a,const point &b,const point &c)
{
    if (sign(dot(a-b,a-c))==0)
        return((b+c)/2);
    if (sign(dot(b-a,b-c))==0)
        return((a+c)/2);
    if (sign(dot(c-a,c-b))==0)
        return((a+b)/2);
    double A=dist(b,c),B=dist(a,c),C=dist(a,b);
    double P=(sqr(A)+sqr(B)+sqr(C))/2;
    double Q=1.0/(1/(P-sqr(A))+1/(P-sqr(B))+1/(P-sqr(C)));
    double d1=Q/(P-sqr(A)),d2=Q/(P-sqr(B)),d3=Q/(P-sqr(C));
    return(a*(1-d1)/2+b*(1-d2)/2+c*(1-d3)/2);
}
inline point project(const point &p,const point &a,const point &b)
{
    double t=dot(p-a,b-a)/dot(b-a,b-a);
    return(a+(b-a)*t);
}
inline double getmin(const point &p,const point &a,const point &b)
{
    point Q=project(p,a,b);
    if (online(Q,a,b))
        return(dist(p,Q));
    return(min(dist(p,a),dist(p,b)));
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,b-a)));
}
inline bool inPolygon(const point &p,int n,point *a)
{
    int res=0;
    for (int i=1;i<=n;i++)
    {
        point A=a[i-1],B=a[i];
        if (online(p,A,B))
            return(true);
        if (sign(A.y-B.y)<=0)
            swap(A,B);
        if (sign(p.y-A.y)>0)
            continue;
        if (sign(p.y-B.y)<=0)
            continue;
        res+=sign(det(B-p,A-p))>0;
    }
    return(res&1);
}
int n;
point p[30];
double ans;
inline void check(const point &P)
{
    if (!inPolygon(P,n,p))
        return;
    double ret=1e100;
    for (int i=1;i<=n;i++)
        ret=min(ret,getmin(P,p[i-1],p[i]));
    ans=max(ans,ret);
}
void work1()
{
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (parellel(p[i]-p[i-1],p[j]-p[j-1]))
                continue;
            for (int k=j+1;k<=n;k++)
            {
                if (parellel(p[i]-p[i-1],p[k]-p[k-1]) || parellel(p[j]-p[j-1],p[k]-p[k-1]))
                    continue;
                point a=intersect(p[i],p[i-1],p[j],p[j-1]),b=intersect(p[i],p[i-1],p[k],p[k-1]),c=intersect(p[j],p[j-1],p[k],p[k-1]);
                check(incenter(a,b,c));
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (!parellel(p[i]-p[i-1],p[j]-p[j-1]))
                continue;
            double len=ptoline(p[i],p[j],p[j-1])/2;
            for (int k=1;k<=n;k++)
            {
                if (parellel(p[i]-p[i-1],p[k]-p[k-1]) || parellel(p[j]-p[j-1],p[k]-p[k-1]))
                    continue;
                point dir=(p[k]-p[k-1]).rotate().unit()*len;
                point P=intersect(p[i],p[i-1],p[k]+dir,p[k-1]+dir);
                point Q=intersect(p[j],p[j-1],p[k]+dir,p[k-1]+dir);
                check((P+Q)/2);
                P=intersect(p[i],p[i-1],p[k]-dir,p[k-1]-dir);
                Q=intersect(p[j],p[j-1],p[k]-dir,p[k-1]-dir);
                check((P+Q)/2);
            }
        }
}
void work2()
{
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=1;k<=n;k++)
            {
                if (online(p[k],p[i],p[i-1]) || online(p[k],p[j],p[j-1]))
                    continue;
                if (parellel(p[i]-p[i-1],p[j]-p[j-1]))
                {
                    int len=ptoline(p[i],p[j],p[j-1])/2;
                    point P=(p[i]+project(p[i],p[j],p[j-1]))/2;
                    point Q=(p[i-1]+project(p[i-1],p[j],p[j-1]))/2;
                    double dis=ptoline(p[k],P,Q);
                    if (sign(dis-len)>0)
                        continue;
                    point T=project(p[k],P,Q);
                    point dir=(P-Q).unit()*sqrt(sqr(len)-sqr(dis));
                    check(T+dir);
                    check(T-dir);
                }
                else
                {
                    point P=intersect(p[i],p[i-1],p[j],p[j-1]);
                    point t1=(p[i]+p[i-1])/2,t2=(p[j]+p[j-1])/2;
                    if (sign(dist(P,t1))==0)
                        t1=p[i];
                    if (sign(dist(P,t2))==0)
                        t2=p[j];
                    if (side(p[k],P,t1)==side(p[k],P,t2))
                        continue;
                    point Q=project(p[k],P,incenter(P,t1,t2));
                    if (sign(dist(p[k],Q)-ptoline(Q,P,t1))>0)
                        continue;
                    double l=0,r=1;
                    for (int T=1;T<=50;T++)
                    {
                        double mid=(l+r)/2;
                        point tmp=P*mid+Q*(1-mid);
                        if (dist(p[k],tmp)>ptoline(tmp,P,t1))
                            r=mid;
                        else
                            l=mid;
                    }
                    double t=(l+r)/2;
                    check(P*t+Q*(1-t));
                }
            }
}
void work3()
{
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=1;k<=n;k++)
            {
                if (online(p[i],p[k],p[k-1]) || online(p[j],p[k],p[k-1]) || side(p[i],p[k],p[k-1])!=side(p[j],p[k],p[k-1]))
                    continue;
                point dir=(p[i]-p[j]).rotate();
                if (parellel(p[k]-p[k-1],dir))
                    continue;
                point P=(p[i]+p[j])/2;
                point Q=intersect(P,P+dir,p[k],p[k-1]);
                if (sign(dist(P,p[i])-ptoline(P,p[k],p[k-1]))>0)
                    continue;
                double l=0,r=1;
                for (int T=1;T<=50;T++)
                {
                    double mid=(l+r)/2;
                    point tmp=P*mid+Q*(1-mid);
                    if (dist(tmp,p[i])>ptoline(tmp,p[k],p[k-1]))
                        l=mid;
                    else
                        r=mid;
                }
                double t=(l+r)/2;
                check(P*t+Q*(1-t));
            }
}
void work4()
{
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
            {
                if (parellel(p[i]-p[j],p[i]-p[k]))
                    continue;
                check(circumcenter(p[i],p[j],p[k]));
            }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    p[0]=p[n];
    work1();
    work2();
    work3();
    work4();
    printf("%.2f\n",ans);
    return(0);
}

