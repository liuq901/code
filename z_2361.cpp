#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;
double inf;
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
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline bool intersect(const point &u1,const point &u2,const point &v1,const point &v2)
{
    return(sign(det(u1-v1,v2-v1))*sign(det(u2-v1,v2-v1))==-1);
}
inline point intersection(const point &u1,const point &u2,const point &v1,const point &v2)
{
    if (sign(det(u1-u2,v1-v2))==0)
        return(point(0,0));
    double t=det(u1-v1,v1-v2)/det(u1-u2,v1-v2);
    return(u1+(u2-u1)*t);
}
typedef vector <point> polygon;
point a[100],b[100];
int n,c[100];
vector <double> ans;
bool check(const polygon &a)
{
    for (int i=0;i<a.size();i++)
        if (fabs(a[i].x)>inf/2 || fabs(a[i].y)>inf/2)
            return(false);
    return(true);
}
double area(const polygon &a)
{
    double ans=0;
    for (int i=1;i<a.size();i++)
        ans+=det(a[i],a[i-1]);
    return(fabs(ans)/2);
}
polygon plane(const polygon &a,point p,point q)
{
    polygon ret;
    for (int i=1;i<a.size();i++)
    {
        if (sign(det(q-p,a[i-1]-p))>=0)
            ret.push_back(a[i-1]);
        if (intersect(a[i-1],a[i],p,q))
            ret.push_back(intersection(a[i-1],a[i],p,q));
    }
    if (!ret.empty())
        ret.push_back(ret[0]);
    return(ret);
}
void dfs(const polygon &now,int dep)
{
    if (now.size()<=3)
        return;
    if (dep==n+1)
    {
        if (check(now))
        {
            double t=area(now);
            if (sign(t)==1)
                ans.push_back(t);
        }
        return;
    }
    dfs(plane(now,a[c[dep]],b[c[dep]]),dep+1);
    dfs(plane(now,b[c[dep]],a[c[dep]]),dep+1);
}
void main2()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
        c[i]=i;
    }
    inf=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            point p=intersection(a[i],b[i],a[j],b[j]);
            inf=max(inf,max(fabs(p.x),fabs(p.y)));
        }
    inf*=100;
    random_shuffle(c+1,c+n+1);
    polygon now;
    now.push_back(point(-inf,-inf));
    now.push_back(point(inf,-inf));
    now.push_back(point(inf,inf));
    now.push_back(point(-inf,inf));
    now.push_back(point(-inf,-inf));
    ans.clear();
    dfs(now,1);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)
        printf("%.4f\n",ans[i]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        main2();
    return(0);
}

