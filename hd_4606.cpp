#include <cstdio>
#include <cstring>
#include <cmath>
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
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(p-a,b-a)));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    return(side(a,c,d)*side(b,c,d)==-1 && side(c,a,b)*side(d,a,b)==-1);
}
point a[310],b[110][2];
double d[310][310];
int n,m,P,ord[110],to[110];
bool vis[110],g[110][110];
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int i=1;i<=n;i++)
    {
        if (vis[i] || !g[x][i])
            continue;
        vis[i]=true;
        if (hungary(to[i]))
        {
            to[i]=x;
            return(true);
        }
    }
    return(false);
}
bool check(double limit)
{
    memset(g,0,sizeof(g));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (d[i][j]<=limit && ord[i]<ord[j])
                g[i][j]=true;
    memset(to,0,sizeof(to));
    int ans=n;
    for (int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans-=hungary(i);
    }
    return(ans<=P);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&P);
        for (int i=1;i<=n;i++)
            a[i].in();
        for (int i=1;i<=m;i++)
        {
            b[i][0].in(),b[i][1].in();
            a[n+2*i-1]=b[i][0];
            a[n+2*i]=b[i][1];
        }
        int N=n+2*m;
        for (int i=1;i<=N;i++)
        {
            d[i][i]=0;
            for (int j=i+1;j<=N;j++)
            {
                d[i][j]=1e10;
                bool flag=true;
                for (int k=1;k<=m;k++)
                    if (intersect(a[i],a[j],b[k][0],b[k][1]))
                    {
                        flag=false;
                        break;
                    }
                if (flag)
                    d[i][j]=dist(a[i],a[j]);
                d[j][i]=d[i][j];
            }
        }
        for (int k=1;k<=N;k++)
            for (int i=1;i<=N;i++)
                for (int j=1;j<=N;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ord[x]=i;
        }
        double l=0,r=1e9;
        for (int t=1;t<=50;t++)
        {
            double mid=(l+r)/2;
            if (check(mid))
                r=mid;
            else
                l=mid;
        }
        printf("%.2f\n",(l+r)/2);
    }
    return(0);
}

