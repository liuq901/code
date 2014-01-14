#include <cstdio>
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
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i].in();
    a[0]=a[n],a[n+1]=a[1];
    int t1=0,t2=0;
    for (int i=1;i<=n;i++)
    {
        t1+=det(a[i]-a[i-1],a[i+1]-a[i])<=0;
        t2+=det(a[i]-a[i-1],a[i+1]-a[i])>=0;
    }
    printf("%d\n",t1==n || t2==n);
    return(0);
}

