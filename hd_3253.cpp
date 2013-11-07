#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
struct diamond
{
    point o;
    int r;
    diamond(point o,int r):o(o),r(r){}
};
point cover[210],center[210];
int r[210];
point get(diamond a,int r,int n)
{
    for (int i=max(1,a.o.x-a.r);i<=min(100000,a.o.x+a.r);i++)
    {
        int lower=max(a.o.y-(a.r-abs(a.o.x-i)),1);
        int upper=min(a.o.y+(a.r-abs(a.o.x-i)),100000);
        for (int j=1;j<=n;j++)
        {
            int u=cover[j].y-(r-abs(cover[j].x-i));
            int v=cover[j].y+(r-abs(cover[j].x-i));
            lower=max(lower,u);
            upper=min(upper,v);
            if (lower>upper)
                break;
        }
        if (lower<=upper)
            return(point(i,lower));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d%d",&cover[i].x,&cover[i].y,&r[i]);
        diamond now=diamond(point(50000,50000),100000);
        for (int i=n;i;i--)
        {
            center[i]=get(diamond(now.o,now.r-r[i]),r[i],i);
            now=diamond(center[i],r[i]);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%d %d\n",center[i].x,center[i].y);
    }
    return(0);
}

