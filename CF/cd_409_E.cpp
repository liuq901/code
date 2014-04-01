#include <cstdio>
#include <cmath>
bool check(int a,int b,double x)
{
    return(fabs(x*sqrt(a*a+4.0*b*b)-a*b)<1e-4);
}
int main()
{
    double x;
    scanf("%lf",&x);
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
            if (check(i,j,x))
            {
                printf("%d %d\n",i,j);
                goto out;
            }
out:
    return(0);
}

