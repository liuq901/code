#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point operator -() const
    {
        return(point(-x,-y));
    }
    point rotate()
    {
        double angle=pi/5;
        return(point(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle)));
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
point a[1000];
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",4*n+1);
    a[1]=point(0,0);
    double c=5/tan(pi/10);
    for (int i=2;i<=n+1;i++)
        a[i]=a[i-1]+point(5,c);
    int now=n+1;
    for (int i=1;i<=n;i++)
    {
        point o=a[i+1],dir(5,c);
        for (int j=1;j<=3;j++)
        {
            dir=(-dir).rotate();
            a[++now]=o+dir;
            o=a[now];
        }
    }
    for (int i=1;i<=now;i++)
        printf("%.10f %.10f\n",a[i].x,a[i].y);
    now=n+1;
    for (int i=1;i<=n;i++)
    {
        printf("%d %d %d %d %d\n",i,now+1,now+3,i+1,now+2);
        now+=3;
    }
    for (int i=1;i<=n;i++)
        printf("%d ",i);
    for (int i=n;i;i--)
    {
        printf("%d %d %d %d ",i+1,now-2,now-1,now);
        now-=3;
    }
    printf("1\n");
    return(0);
}

