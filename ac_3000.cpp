#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;
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
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
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
inline bool operator <(const point &a,const point &b)
{
    if (sign(a.x-b.x)==0)
        return(a.y<b.y);
    return(a.x<b.x);
}
double sqr(double x)
{
    return(x*x);
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
bool online(const point &a,const point &b,const point &p)
{
    return(sign(dot(p-a,p-b))<=0);
}
bool intersect(const point &u1,const point &u2,const point &v1,const point &v2,point &p)
{
    if (sign(det(u1-u2,v1-v2))==0)
        return(false);
    double t=det(u1-v1,v1-v2)/det(u1-u2,v1-v2);
    p=u1+(u2-u1)*t;
    return(online(u1,u2,p) && online(v1,v2,p));
}
point a[110],b[110];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            a[i].in();
            b[i].in();
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            vector <point> s;
            for (int j=1;j<=n;j++)
            {
                point p;
                if (intersect(a[i],b[i],a[j],b[j],p))
                    s.push_back(p);
            }
            s.push_back(a[i]);
            s.push_back(b[i]);
            sort(s.begin(),s.end());
            for (int j=1;j<s.size();j++)
            {
                double len=dist(s[j],s[j-1]);
                if (j==1)
                    len+=25;
                if (j==s.size()-1)
                    len+=25;
                ans+=int(len/50+eps);
            }
        }
        static int id=0;
        printf("Map %d\nTrees = %d\n",++id,ans);
    }
    return(0);
}

