#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        double x=a*c/b;
        static int id=0;
        printf("Case %d: ",++id);
        if (b>x)
            printf("%.10f\n",(a+x)*(c+x)/(b-x)+x);
        else
            printf("-1\n");
    }
    return(0);
}

