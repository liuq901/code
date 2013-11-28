#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
point a[110];
template <class T> inline T sqr(const T &x)
{
    return(x*x);
}
double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i].in();
    point o(0.5,0.5);
    double len=0;
    for (int i=1;i<=n;i++)
        len=max(len,dist(a[i],o));
    printf("%.10f %.10f %.10f\n",o.x,o.y,len);
    return(0);
}

