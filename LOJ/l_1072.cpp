#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double r;
        int n;
        scanf("%lf%d",&r,&n);
        double a=pi/n;
        static int id=0;
        printf("Case %d: %.10f\n",++id,r*sin(a)/(1+sin(a)));
    }
    return(0);
}

