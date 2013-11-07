#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const int T=1000000;
struct point
{
    int x,y,id;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline ll det(const point &a,const point &b)
{
    return(ll(a.x)*b.y-ll(a.y)*b.x);
}
point p[10],b[10],a[5010];
bool check()
{
    sort(b+1,b+6);
    int m=0;
    for (int i=1;i<=5;i++)
    {
        while (m>=2 && det(b[i]-p[m],p[m]-p[m-1])>0)
            m--;
        p[++m]=b[i];
    }
    int limit=m;
    for (int i=4;i;i--)
    {
        while (m>limit && det(b[i]-p[m],p[m]-p[m-1])>0)
            m--;
        p[++m]=b[i];
    }
    return(m==6);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id=i;
    }
    random_shuffle(a+1,a+n+1);
    for (int t=1;t<=T;t++)
    {
        for (int i=1;i<=5;i++)
        {
            int x=rand()%(n-i+1)+i;
            swap(a[i],a[x]);
            b[i]=a[i];
        }
        if (check())
        {
            printf("Yes\n");
            for (int i=1;i<=5;i++)
                printf("%d%c",p[i].id,i==5?'\n':' ');
            goto last;
        }
    }
    printf("No\n");
last:
    return(0);
}

