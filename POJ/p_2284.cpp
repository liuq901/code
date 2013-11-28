#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){};
    point(double x,double y):x(x),y(y){}
};
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
inline bool parellel(const point &a,const point &b,const point &c,const point &d)
{
    return(sign(det(a-b,c-d))==0);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(b-a,c-a);
    double s2=det(b-a,d-a);
    return((c*s2-d*s1)/(s2-s1));
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,p-b))==0 && sign(dot(p-a,p-b))<=0);
}
point A[1000];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <point> p;
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&A[i].x,&A[i].y);
            p.push_back(A[i]);
        }
        for (int i=2;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            {
                if (parellel(A[i-1],A[i],A[j-1],A[j]))
                    continue;
                point P=intersect(A[i-1],A[i],A[j-1],A[j]);
                if (online(P,A[i-1],A[i]) && online(P,A[j-1],A[j]))
                    p.push_back(P);
            }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        int ans=2-p.size();
        for (int i=2;i<=n;i++)
        {
            int sum=0;
            for (int j=0;j<p.size();j++)
                if (online(p[j],A[i-1],A[i]))
                    sum++;
            ans+=sum-1;
        }
        static int id=0;
        printf("Case %d: There are %d pieces.\n",++id,ans);
    }
    return(0);
}

