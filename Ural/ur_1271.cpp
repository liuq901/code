#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
        x<<=1,y<<=1;
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
inline point operator /(const point &a,int b)
{
    return(point(a.x/b,a.y/b));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline bool operator ==(const point &a,const point &b)
{
    return(a.x==b.x && a.y==b.y);
}
inline ll dot(const point &a,const point &b)
{
    return(ll(a.x)*b.x+ll(a.y)*b.y);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
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
    return(dot(p-a,p-b)<=0 && det(p-a,p-b)==0);
}
inline int side(const point &p,const point &a,const point &b)
{
    ll tmp=det(p-a,b-a);
    return(tmp<0?-1:tmp>0);
}
inline bool intersect(const point &a,const point &b,const point &c,const point &d)
{
    return(side(a,c,d)*side(b,c,d)==-1 && side(c,a,b)*side(d,a,b)==-1);
}
inline bool inTriangle(const point &p,point *a)
{
    double area=abs(det(a[0]-a[1],a[0]-a[2]));
    double area1=abs(det(p-a[0],p-a[1]));
    double area2=abs(det(p-a[0],p-a[2]));
    double area3=abs(det(p-a[1],p-a[2]));
    return(area1>0 && area2>0 && area3>0 && area1+area2+area3==area);
}
inline bool inPolygon(const point &p,int n,point *a)
{
    a[0]=a[n];
    int res=0;
    for (int i=1;i<=n;i++)
    {
        point A=a[i-1],B=a[i];
        if (online(p,A,B))
            return(false);
        if (A.y<=B.y)
            swap(A,B);
        if (p.y>A.y || p.y<=B.y)
            continue;
        res+=det(B-p,A-p)>0;
    }
    return(res&1);
}
point p[50][3],a[400];
int n,m,X,Y;
bool check(const point &P)
{
    for (int i=0;i<3;i++)
    {
        point dir=p[0][i]-p[0][0];
        int x=P.x+dir.x,y=P.y+dir.y;
        if (x<0 || x>X || y<0 || y>Y)
            return(false);
    }
    for (int i=1;i<=m;i++)
        if (P==a[i])
            return(false);
    return(true);
}
point b[10];
int tot;
void convex()
{
    sort(b+1,b+tot+1);
    point s[10];
    int top=0;
    for (int i=1;i<=tot;i++)
    {
        while (top>=2 && det(s[top]-s[top-1],b[i]-s[top])<=0)
            top--;
        s[++top]=b[i];
    }
    int limit=top;
    for (int i=tot-1;i>=1;i--)
    {
        while (top>limit && det(s[top]-s[top-1],b[i]-s[top])<=0)
            top--;
        s[++top]=b[i];
    }
    for (int i=1;i<top;i++)
        b[i]=s[i];
    tot=top-1;
}
bool ok(int u,int v)
{
    tot=0;
    for (int i=0;i<3;i++)
    {
        point dir=a[u]-p[0][0];
        b[++tot]=p[0][i]+dir;
        dir=a[v]-p[0][0];
        b[++tot]=p[0][i]+dir;
    }
    convex();
    b[0]=b[tot];
    for (int i=1;i<=n;i++)
    {
        int sum=0;
        for (int j=0;j<3;j++)
        {
            if (inPolygon(p[i][j],tot,b) || inPolygon((p[i][j]+p[i][(j+1)%3])/2,tot,b))
                return(false);
            bool flag=false;
            for (int k=1;k<=tot;k++)
            {
                if (intersect(b[k-1],b[k],p[i][j],p[i][(j+1)%3]))
                    return(false);
                if (online(p[i][j],b[k-1],b[k]))
                    flag=true;
            }
            sum+=flag;
        }
        for (int j=1;j<=tot;j++)
            if (inTriangle(b[j],p[i]) || inTriangle((b[j]+b[j-1])/2,p[i]))
                return(false);
    }
    return(true);
}
void build()
{
    a[2]=p[0][0];
    m=2;
    for (int i=1;i<=n;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
            {
                point dir=p[i][j]-p[0][k];
                if (check(p[0][0]+dir))
                    a[++m]=p[0][0]+dir;
            }
}
double d[400];
bool vis[400];
void dijkstra()
{
    for (int i=1;i<=m;i++)
        d[i]=1e100;
    d[2]=0;
    for (int i=1;i<=m;i++)
    {
        int k=-1;
        for (int j=1;j<=m;j++)
            if (!vis[j] && (k==-1 || d[j]<d[k]))
                k=j;
        if (d[k]>1e95)
            break;
        vis[k]=true;
        for (int j=1;j<=m;j++)
            if (!vis[j] && ok(k,j))
                d[j]=min(d[j],d[k]+dist(a[k],a[j]));
    }
}
int main()
{
    scanf("%d%d",&X,&Y);
    X<<=1,Y<<=1;
    for (int i=0;i<3;i++)
        p[0][i].in();
    a[1].in();
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=0;j<3;j++)
            p[i][j].in();
    bool flag=check(a[1]);
    if (flag)
    {
        build();
        dijkstra();
    }
    if (!flag || d[1]>1e95)
        printf("-1\n");
    else
        printf("%.10f\n",d[1]/2);
    return(0);
}

