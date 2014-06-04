#include <cstdio>
#include <cmath>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double L,W;
        scanf("%lf%lf",&L,&W);
        double x=(L+W-sqrt(L*L+W*W-L*W))/3;
        static int id=0;
        printf("Case %d: %.10f\n",++id,(L-x)*(W-x)*x/2);
    }
    return(0);
}

