#include <cstdio>
#include <cmath>
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
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int sign(double x,double eps=1e-10)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator ==(const point &a,const point &b)
{
    return(sign(a.x-b.x)==0 && sign(a.y-b.y)==0);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool same(double x,double y)
{
    return(sign(x-y)==0);
}
point a[25010],b[25010];
int n,nn,m,c[25010];
double angle[25010],len[25010],f[100010],g[50010];
inline bool cmp(int x,int y)
{
    return(sign(angle[x]-angle[y])<0 || sign(angle[x]-angle[y])==0 && sign(len[x]-len[y])<0);
}
void work(point *a,int &n,double *f)
{
    point o(0,0);
    for (int i=1;i<=n;i++)
        o=o+a[i];
    o=o/n;
    int t=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==o)
            continue;
        a[++t]=a[i];
    }
    n=t;
    for (int i=1;i<=n;i++)
    {
        angle[i]=atan2(a[i].y-o.y,a[i].x-o.x);
        len[i]=dist(a[i],o);
        c[i]=i;
    }
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        int x=c[i],y=i==1?c[n]:c[i-1];
        f[2*i-2]=len[x]/len[y];
        f[2*i-1]=angle[x]-angle[y];
        if (sign(f[2*i-1])==-1)
            f[2*i-1]+=2*pi;
    }
}
int nxt[50010];
bool KMP(double *a,int n,double *b,int m)
{
    nxt[0]=-1;
    for (int i=1;i<m;i++)
    {
        int t=nxt[i-1];
        while (t!=-1 && !same(b[i-1],b[t]))
            t=nxt[t];
        nxt[i]=t+1;
    }
    int q=0;
    for (int i=0;i<n;i++)
    {
        while (q!=-1 && !same(a[i],b[q]))
            q=nxt[q];
        q++;
        if (q==m)
            return(true);
    }
    return(false);
}
bool check()
{
    if (m!=nn)
        return(false);
    work(b,m,g);
    if (m!=n)
        return(false);
    if (m==0)
        return(true);
    if (KMP(f,4*n,g,2*m))
        return(true);
    for (int i=1;i<=m;i++)
        b[i].x=-b[i].x;
    work(b,m,g);
    return(KMP(f,4*n,g,2*m));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        nn=n;
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        work(a,n,f);
        for (int i=0;i<2*n;i++)
            f[i+2*n]=f[i];
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%d",&m);
            for (int i=1;i<=m;i++)
                scanf("%lf%lf",&b[i].x,&b[i].y);
            printf("%s\n",check()?"Yes":"No");
        }
        printf("\n");
    }
    return(0);
}

