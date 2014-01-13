#include <cstdio>
#include <cmath>
int main()
{
    double x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    double x=x1-x2,y=y1-y2;
    printf("%.10f\n",sqrt(x*x+y*y));
    return(0);
}

