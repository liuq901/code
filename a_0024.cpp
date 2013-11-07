#include <cstdio>
#include <cmath>
int main()
{
    double v;
    while (scanf("%lf",&v)==1)
    {
        for (int i=1;;i++)
        {
            double h=5*i-5;
            double t=sqrt(h/4.9);
            if (9.8*t>=v)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return(0);
}

