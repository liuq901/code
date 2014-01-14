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
inline int contain(const point &p,point *a,int n)
{
    a[0]=a[n];
    int res=0;
    for (int i=1;i<=n;i++)
    {
        point A=a[i-1],B=a[i];
        if (online(p,A,B))
            return(1);
        if (A.y<=B.y)
            swap(A,B);
        if (p.y>A.y || p.y<=B.y)
            continue;
        res+=det(B-p,A-p)>0;
    }
    return(res&1?2:0);
}
point a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i].in();
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        point p;
        p.in();
        printf("%d\n",contain(p,a,n));
    }
    return(0);
}

