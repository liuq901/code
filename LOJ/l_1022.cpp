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
        scanf("%lf",&r);
        static int id=0;
        printf("Case %d: %.2f\n",++id,(4-pi)*r*r);
    }
    return(0);
}

