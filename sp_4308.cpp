#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;
struct point
{
    double x,y;
    int id1,id2;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
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
inline double operator *(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline bool cmp(const point &a,const point &b)
{
    if (sign(a.x-b.x)==0)
        return(a.y<b.y);
    return(a.x<b.x);
}
point a[1010],b[1010];
vector <point> s,f[1010];
int d[1010],c[1010][1010];
void intersect(int x,int y)
{
    if (sign((a[x]-b[x])*(a[y]-b[y]))==0)
        return;
    double t=(a[x]-a[y])*(a[y]-b[y])/((a[x]-b[x])*(a[y]-b[y]));
    point p=a[x]+(b[x]-a[x])*t;
    p.id1=x,p.id2=y;
    s.push_back(p);
}
int calc(int x,int y)
{
    if (c[x][y]==0)
        return(sign((a[y]-a[x])*(b[x]-a[x]))>0?d[y]:0);
    if (d[y]==1)
        return(0);
    point Q=f[y][d[y]-1];
    if (c[y][x]==d[y])
        Q=Q+(Q-f[y][0]);
    return(sign((Q-a[x])*(b[x]-a[x]))>0?d[y]-c[y][x]:c[y][x]-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        a[i].in();
        b[i].in();
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            intersect(i,j);
    sort(s.begin(),s.end(),cmp);
    for (int i=0;i<s.size();i++)
    {
        int x=s[i].id1,y=s[i].id2;
        f[x].push_back(s[i]);
        f[y].push_back(s[i]);
        c[x][y]=++d[x];
        c[y][x]=++d[y];
    }
    int tot=s.size();
    for (int i=1;i<=n;i++)
    {
        int sum=0;
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            sum+=calc(i,j);
        }
        sum>>=1;
        printf("%d\n",abs(tot-d[i]-sum-sum));
    }
    return(0);
}

