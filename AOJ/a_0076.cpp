#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point rotate() const
    {
        return(point(-y,x));
    }
    point unit() const
    {
        double t=sqrt(x*x+y*y);
        return(point(x/t,y/t));
    }
    void out() const
    {
        printf("%.10f\n%.10f\n",x,y);
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
point a[1010];
void init()
{
    a[1]=point(1,0);
    for (int i=2;i<=1000;i++)
        a[i]=a[i-1]+a[i-1].rotate().unit();
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        a[n].out();
    }
    return(0);
}

