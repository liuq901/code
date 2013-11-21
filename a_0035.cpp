#include <cstdio>
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point a[10];
int main()
{
    while (scanf("%lf",&a[1].x)==1)
    {
        scanf(",%lf",&a[1].y);
        for (int i=2;i<=4;i++)
            scanf(",%lf,%lf",&a[i].x,&a[i].y);
        a[0]=a[4];
        a[5]=a[1];
        int cnt=0;
        for (int i=1;i<=4;i++)
            cnt+=sign(det(a[i]-a[i-1],a[i+1]-a[i]))>0;
        printf("%s\n",cnt==0 || cnt==4?"YES":"NO");
    }
    return(0);
}

