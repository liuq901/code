#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double a,b,h;
        scanf("%lf%lf%lf",&a,&b,&h);
        printf("%.2f\n",h/a*b);
    }
    return(0);
}

