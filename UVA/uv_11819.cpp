#include <cstdio>
typedef long long ll;
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
    point rotate() const
    {
        return(point(-y,x));
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline ll dot(const point &a,const point &b)
{
    return(ll(a.x)*b.x+ll(a.y)*b.y);
}
inline int sign(ll x)
{
    return(x<0?-1:x>0);
}
point o,p[10010];
int a[10010],b[10010],c[10010];
int main()
{
    while (1)
    {
        o.in();
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            p[i].in();
            scanf("%dx%dy%d=0",&a[i],&b[i],&c[i]);
        }
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            point dir=(p[i]-o).rotate();
            sum+=sign(dot(dir,point(a[i],b[i])))==1;
        }
        printf("%d\n",sum*(n-sum));
    }
    return(0);
}

