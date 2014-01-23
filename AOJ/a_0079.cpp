#include <cstdio>
#include <cmath>
struct point
{
    double x,y;
    bool in()
    {
        return(scanf("%lf,%lf",&x,&y)==2);
    }
};
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point a[30];
int main()
{
    int n=1;
    while (a[n].in())
        n++;
    n--;
    a[0]=a[n];
    double ans=0;
    for (int i=1;i<=n;i++)
        ans+=det(a[i-1],a[i]);
    printf("%.10f\n",fabs(ans)/2);
    return(0);
}

