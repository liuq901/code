#include <cstdio>
#include <algorithm>
using namespace std;
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
inline int dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline bool online(const point &p,const point &a,const point &b)
{
    return(det(p-a,p-b)==0 && dot(p-a,p-b)<=0);
}
inline bool in(const point &p,point list[],int n)
{
    int res=0;
    for (int i=1;i<=n;i++)
    {
        point a=list[i-1],b=list[i];
        if (online(p,a,b))
            return(true);
        if (a.y<=b.y)
            swap(a,b);
        if (p.y>a.y || p.y<=b.y)
            continue;
        res+=det(b-p,a-p)>0;
    }
    return(res&1);
}
point a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        a[0]=a[n];
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            point p;
            scanf("%d%d",&p.x,&p.y);
            printf("%s\n",in(p,a,n)?"Yes":"No");
        }
    }
    return(0);
}

