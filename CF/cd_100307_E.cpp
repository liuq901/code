#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(double x,double eps=1e-10)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<0);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
vector <point> up,down;
point a[100010],b[100010];
void convex(int n)
{
    sort(a+1,a+n+1);
    int m=0;
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    int l=1,r=m;
    while (l<r && sign(b[l].x-b[l+1].x)==0)
        l++;
    while (l<r && sign(b[r].x-b[r-1].x)==0)
        r--;
    down=vector <point>(b+l,b+r+1);
    m=0;
    for (int i=n;i;i--)
    {
        while (m>=2 && sign(det(b[m]-b[m-1],a[i]-b[m]))<=0)
            m--;
        b[++m]=a[i];
    }
    l=1,r=m;
    while (l<r && sign(b[l].x-b[l+1].x)==0)
        l++;
    while (l<r && sign(b[r].x-b[r-1].x)==0)
        r--;
    up=vector <point>(b+l,b+r+1);
    reverse(up.begin(),up.end());
}
double get(const vector <point> &a,double x)
{
    int t=lower_bound(a.begin(),a.end(),point(x,-1e100))-a.begin();
    if (t==a.size())
        t--;
    if (t==0)
        return(a[t].y);
    return((x-a[t-1].x)*(a[t].y-a[t-1].y)/(a[t].x-a[t-1].x)+a[t-1].y);
}
double calc(double x0,double x1)
{
    return((x1-x0)*(min(get(up,x0),get(up,x1))-max(get(down,x0),get(down,x1))));
}
double X;
double calc(double w)
{
    double l=down.begin()->x,r=down.back().x-w;
    for (int T=1;T<=100;T++)
    {
        double lx=(2*l+r)/3,rx=(l+2*r)/3;
        if (calc(lx,lx+w)<calc(rx,rx+w))
            l=lx;
        else
            r=rx;
    }
    X=l;
    return(calc(X,X+w));
}
int main()
{
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&a[i].x,&a[i].y);
    convex(n);
    double l=0,r=down.back().x-down.begin()->x;
    for (int T=1;T<=100;T++)
    {
        double lx=(2*l+r)/3,rx=(l+2*r)/3;
        if (calc(lx)<calc(rx))
            l=lx;
        else
            r=rx;
    }
    calc(l);
    double x0=X,x1=X+l,y0=max(get(down,x0),get(down,x1)),y1=min(get(up,x0),get(up,x1));
    printf("%.10f %.10f %.10f %.10f\n",x0,y0,x1,y1);
    return(0);
}

