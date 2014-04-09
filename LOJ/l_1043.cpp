#include <cstdio>
#include <cmath>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double l,t;
        scanf("%lf%*lf%*lf%lf",&l,&t);
        static int id=0;
        printf("Case %d: %.10f\n",++id,l*sqrt(1/(1/t+1)));
    }
    return(0);
}

