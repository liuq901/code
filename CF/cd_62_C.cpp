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
point a[110][5];
int n;
bool intriangle(const point &p,int id)
{
    double now=0;
    for (int i=1;i<=3;i++)
        now+=fabs(det(a[id][i]-p,a[id][i-1]-p));
    return(sign(now-fabs(det(a[id][3]-a[id][1],a[id][2]-a[id][1])))==0);
}
bool online(const point &p,const point &a,const point &b)
{
    return(sign(dot(a-p,b-p))<=0);
}
bool intersect(const point &u1,const point &u2,const point &v1,const point &v2,point &P)
{
    if (sign(det(u1-u2,v1-v2))==0)
        return(false);
    double t=det(u1-v1,v1-v2)/det(u1-u2,v1-v2);
    P=u1+(u2-u1)*t;
    return(online(P,u1,u2) && online(P,v1,v2));
}
double calc(const point &p,const point &q,int id)
{
    vector <point> b;
    b.push_back(p);
    b.push_back(q);
    for (int i=1;i<=n;i++)
    {
        if (i==id)
            continue;
        for (int j=1;j<=3;j++)
        {
            point x;
            if (intersect(p,q,a[i][j-1],a[i][j],x))
                b.push_back(x);
        }
    }
    double ans=0;
    sort(b.begin(),b.end());
    for (int i=1;i<b.size();i++)
    {
        point x=(b[i-1]+b[i])*0.5;
        bool flag=true;
        for (int j=1;j<=n;j++)
        {
            if (j==id)
                continue;
            if (intriangle(x,j))
            {
                flag=false;
                break;
            }
        }
        ans+=flag*dist(b[i-1],b[i]);
    }
    return(ans);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=3;j++)
            scanf("%lf%lf",&a[i][j].x,&a[i][j].y);
        a[i][0]=a[i][3];
    }
    double ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=3;j++)
            ans+=calc(a[i][j-1],a[i][j],i);
    printf("%.10f\n",ans);
    return(0);
}

