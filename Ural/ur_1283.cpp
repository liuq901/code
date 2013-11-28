#include <cstdio>
#include <cmath>
int main()
{
    double x,y,r;
    scanf("%lf%lf%lf",&x,&y,&r);
    if (x<=y)
        printf("0\n");
    else
    {
        r=1-r/100;
        printf("%d\n",int(ceil(log(y/x)/log(r))));
    }
    return(0);
}

