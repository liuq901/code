#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
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
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    if (sign(a.x-b.x)==0)
        return(a.y<b.y);
    return(a.x<b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point S,T,a[110];
double v,V,d[110][110];
int n;
bool online(const point &a,const point &b,const point &p)
{
    return(fabs(det(a-p,b-p))<1e-6 && sign(dot(a-p,b-p))<=0);
}
bool intersect(const point &a,const point &b,const point &c,const point &d,point &e)
{
    double s1=det(c-a,d-a);
    double s2=det(d-b,c-b);
    if (sign(s1+s2)==0)
        return(false);
    e=(b-a)*(s1/(s1+s2))+a;
    return(online(a,b,e) && online(c,d,e));
}
int in(const point &P)
{
    int res=0;
    point A,B;
    for (int i=1;i<=n;i++)
    {
        A=a[i-1],B=a[i];
        if (online(A,B,P))
            return(-1);
        if (sign(A.y-B.y)<=0)
            swap(A,B);
        if (sign(P.y-A.y)>0)
            continue;
        if (sign(P.y-B.y)<=0)
            continue;
        res+=sign(det(B-P,A-P))>0;
    }
    return(res&1);
}
bool check(const point &u,const point &v)
{
    vector <point> s;
    for (int i=1;i<=n;i++)
    {
        point p;
        if (intersect(u,v,a[i-1],a[i],p))
            s.push_back(p);
    }
    s.push_back(u);
    s.push_back(v);
    sort(s.begin(),s.end());
    for (int i=1;i<s.size();i++)
    {
        point mid=(s[i-1]+s[i])/2;
        if (in(mid)==1)
            return(false);
    }
    return(true);
}
point calc(double t)
{
    double tot=0;
    for (int i=1;i<=n;i++)
    {
        double len=dist(a[i-1],a[i]),now=len/v;
        tot+=now;
    }
    t-=tot*ll(t/tot);
    for (int i=1;i<=n;i++)
    {
        double len=dist(a[i],a[i+1]),now=len/v;
        if (t<=now)
            return(a[i]+(a[i+1]-a[i])/now*t);
        t-=now;
    }
}
queue <int> Q;
bool vis[110];
double cost[110];
double spfa()
{
    for (int i=1;i<=n+1;i++)
        cost[i]=1e10;
    cost[0]=0;
    vis[0]=true;
    Q.push(0);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        vis[x]=false;
        for (int i=0;i<=n+1;i++)
            if (sign(cost[x]+d[x][i]-cost[i])<0)
            {
                cost[i]=cost[x]+d[x][i];
                if (!vis[i])
                {
                    vis[i]=true;
                    Q.push(i);
                }
            }
    }
    return(cost[n+1]);
}
bool ok(double t)
{
    T=calc(t);
    for (int i=0;i<=n;i++)
        d[i][n+1]=d[n+1][i]=1e10;
    for (int i=1;i<=n;i++)
        if (check(a[i],T))
            d[i][n+1]=d[n+1][i]=dist(a[i],T);
    if (check(S,T))
        d[0][n+1]=d[n+1][0]=dist(S,T);
    return(spfa()<=t*V);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            a[i].in();
        a[0]=a[n];
        a[n+1]=a[1];
        S.in();
        scanf("%lf%lf",&v,&V);
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=n+1;j++)
                d[i][j]=d[j][i]=1e10;
        for (int i=1;i<=n;i++)
        {
            if (check(a[i],S))
                d[i][0]=d[0][i]=dist(a[i],S);
            for (int j=i+1;j<=n;j++)
                if (check(a[i],a[j]))
                    d[i][j]=d[j][i]=dist(a[i],a[j]);
        }
        double l=0,r=1e10;
        for (int time=1;time<=100;time++)
        {
            double mid=(l+r)/2;
            if (ok(mid))
                r=mid;
            else
                l=mid;
        }
        int ans=int((l+r)/2*60+0.5);
        static int id=0;
        printf("Case %d: Time = %d:%02d\n",++id,ans/60,ans%60);
    }
    return(0);
}

