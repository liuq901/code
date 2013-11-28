#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
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
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(sign(dot(a-p,b-p))<=0);
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d,point &p)
{
    double s1=det(b-a,c-a);
    double s2=det(b-a,d-a);
    if (sign(s1-s2)==0)
        return(false);
    p=(d*s1-c*s2)/(s1-s2);
    return(online(p,a,b) && online(p,c,d));
}
inline point reflect(const point &p,const point &a,const point &b)
{
    double rate=dot(p-a,b-a)/dot(b-a,b-a);
    point P=a+(b-a)*rate;
    return(P*2-p);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
int n,p[10];
point a[10][10],b[10][10];
vector <int> ans;
bool check(const point &o,int m)
{
    if (m==0)
        return(false);
    for (int i=1;i<=m;i++)
    {
        double mi=1e10,len=-1;
        point Q;
        for (int j=1;j<=n;j++)
        {
            point P;
            bool flag=intersect(o,point(0,0),a[i][j],b[i][j],P);
            if (j==p[i] && !flag)
                return(false);
            if (j==p[i])
                Q=P;
            if (j==p[i-1])
                len=dist(point(0,0),P);
        }
        for (int j=1;j<=n;j++)
        {
            point P;
            bool flag=intersect(o,point(0,0),a[i][j],b[i][j],P);            
            if (flag)
            {
                double dis=dist(point(0,0),P);
                if (sign(dis-len)>0)
                    mi=min(mi,dis);
            }
        }
        if (sign(dist(point(0,0),Q)-mi)!=0)
            return(false);
    }
    return(true);
}
void dfs(const point &o,int dep)
{
    double angle=atan2(o.y,o.x)/pi*180;
    char buf[10];
    sprintf(buf,"%.0f",angle);
    int x;
    sscanf(buf,"%d",&x);
    if (x<0)
        x+=360;
    if (check(o,dep-1))
        ans.push_back(x);
    if (dep==8)
        return;
    for (int i=1;i<=n;i++)
    {
        if (i==p[dep-1])
            continue;
        p[dep]=i;
        for (int j=1;j<=n;j++)
        {
            a[dep+1][j]=reflect(a[dep][j],a[dep][i],b[dep][i]);
            b[dep+1][j]=reflect(b[dep][j],a[dep][i],b[dep][i]);
        }
        dfs(reflect(o,a[dep][i],b[dep][i]),dep+1);
    }
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&a[1][i].x,&a[1][i].y,&b[1][i].x,&b[1][i].y);
        ans.clear();
        dfs(point(0,0),1);
        if (ans.empty())
            printf("no danger\n");
        else
        {
            sort(ans.begin(),ans.end());
            ans.erase(unique(ans.begin(),ans.end()),ans.end());
            for (int i=0;i<ans.size();i++)
                printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
        }
    }
    return(0);
}

