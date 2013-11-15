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
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<=0);
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,b-a),s2=det(d-a,b-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline bool inPolygon(const point &p,point *a,int n)
{
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        point A=a[i-1],B=a[i];
        if (online(p,A,B))
            return(true);
        if (sign(A.y-B.y)<=0)
            swap(A,B);
        if (sign(p.y-A.y)>0 || sign(p.y-B.y)<=0)
            continue;
        ret+=sign(det(B-p,A-p))>0;
    }
    return(ret&1);
}
point a[110];
double calc(const point &A,const point &B,int n)
{
    vector <point> lq;
    for (int i=1;i<=n;i++)
    {
        if (parellel(B-A,a[i]-a[i-1]))
            continue;
        point tmp=intersect(A,B,a[i-1],a[i]);
        if (sign(dot(tmp-a[i-1],tmp-a[i]))<=0)
            lq.push_back(tmp);
    }
    sort(lq.begin(),lq.end());
    lq.erase(unique(lq.begin(),lq.end()),lq.end());
    int L=-1,R;
    double ans=0;
    for (int i=1;i<lq.size();i++)
    {
        point mid=(lq[i-1]+lq[i])/2;
        if (inPolygon(mid,a,n))
        {
            if (L==-1)
                L=i-1;
            R=i;
        }
        else
        {
            if (L!=-1)
                ans=max(ans,dist(lq[L],lq[R]));
            L=-1;
        }
    }
    if (L!=-1)
        ans=max(ans,dist(lq[L],lq[R]));
    return(ans);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        a[0]=a[n];
        double ans=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                ans=max(ans,calc(a[i],a[j],n));
        static int id=0;
        printf("Case %d: %.10f\n",++id,ans);
    }
    return(0);
}

