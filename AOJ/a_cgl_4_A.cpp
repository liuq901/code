#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
    void out()
    {
        printf("%d %d\n",x,y);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline bool operator <(const point &a,const point &b)
{
    return(a.y<b.y || a.y==b.y && a.x<b.x);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int convex(point *a,int n)
{
    static point b[100010];
    int m=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        while (m>=2 && det(b[m]-b[m-1],a[i]-b[m])<0)
            m--;
        b[++m]=a[i];
    }
    int limit=m;
    for (int i=n-1;i;i--)
    {
        while (m>limit && det(b[m]-b[m-1],a[i]-b[m])<0)
            m--;
        b[++m]=a[i];
    }
    for (int i=1;i<m;i++)
        a[i]=b[i];
    return(m-1);
}
point a[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i].in();
    n=convex(a,n);
    printf("%d\n",n);
    for (int i=1;i<=n;i++)
        a[i].out();
    return(0);
}

