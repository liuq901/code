#include <cstdio>
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
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(b-a,c-a),s2=det(b-a,d-a);
    return((c*s2-d*s1)/(s2-s1));
}
point a[110],b[110];
int calc(int n)
{
    vector <point> s;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        vector <point> p;
        for (int j=1;j<=n;j++)
        {
            if (parellel(b[i]-a[i],b[j]-a[j]))
                continue;
            point tmp=intersect(a[i],b[i],a[j],b[j]);
            if (sign(dot(tmp-a[i],tmp-b[i]))<=0 && sign(dot(tmp-a[j],tmp-b[j]))<=0)
            {
                p.push_back(tmp);
                s.push_back(tmp);
            }
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        ans+=p.size()-1;
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    ans-=s.size();
    return(ans+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,L,W;
        scanf("%d%d%d",&n,&L,&W);
        for (int i=1;i<=n;i++)
            a[i].in(),b[i].in();
        a[n+1]=point(0,0),b[n+1]=point(L,0);
        a[n+2]=point(L,0),b[n+2]=point(L,W);
        a[n+3]=point(L,W),b[n+3]=point(0,W);
        a[n+4]=point(0,W),b[n+4]=point(0,0);
        static int id=0;
        printf("Case %d: %d\n",++id,calc(n+4));
    }
    return(0);
}

