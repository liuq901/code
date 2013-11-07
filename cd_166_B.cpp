#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline bool operator ==(const point &a,const point &b)
{
    return(a.x==b.x && a.y==b.y);
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
point a[N],b[N];
vector <point> ans1,ans2;
vector <point> convex(point *a,int n)
{
    sort(a+1,a+n+1);
    int m=0;
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && det(a[i]-b[m],b[m]-b[m-1])<0)
            m--;
        b[++m]=a[i];
    }
    int limit=m;
    for (int i=n-1;i;i--)
    {
        while (m>limit && det(a[i]-b[m],b[m]-b[m-1])<0)
            m--;
        b[++m]=a[i];
    }
    vector <point> ret(b+1,b+m+1);
    return(ret);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    ans1=convex(a,n);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d",&a[i+n].x,&a[i+n].y);
    ans2=convex(a,n+m);
    printf("%s\n",ans1==ans2?"YES":"NO");
    return(0);
}

