#include <cstdio>
#include <cmath>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double n,a,b;
        scanf("%lf%lf%lf",&n,&a,&b);
        static int id=0;
        printf("Case %d: ",++id);
        if (fabs(a-b)<1e-8)
            printf("%.10f\n",pow(a,n));
        else
            printf("%.10f\n",(pow(b,n+1)-pow(a,n+1))/(n+1)/(b-a));
    }
    return(0);
}

