#include <cstdio>
#include <cmath>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        double x=n/2.0;
        while (fabs(x*x*x-n)>=1e-5*n)
            x=x-(x*x*x-n)/(3*x*x);
        printf("%.10f\n",x);
    }
    return(0);
}

