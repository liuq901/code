#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
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
ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
point a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    a[0]=a[n];
    int l=min(a[1].x,a[2].x),r=max(a[1].x,a[2].x);
    for (int i=1;i<=n;i++)
    {
        while (l<=r && det(a[i]-a[i-1],point(l,a[1].y)-a[i-1])>0)
            l++;
        while (r>=l && det(a[i]-a[i-1],point(r,a[1].y)-a[i-1])>0)
            r--;
    }
    printf("%d\n",r-l+1);
    return(0);
}

