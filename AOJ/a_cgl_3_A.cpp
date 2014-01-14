#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
inline double det(const point &a,const point &b)
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
    a[0]=a[n];
    double area=0;
    for (int i=1;i<=n;i++)
        area+=det(a[i],a[i-1]);
    printf("%.1f\n",fabs(area)/2);
    return(0);
}

