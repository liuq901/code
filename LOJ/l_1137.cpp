#include <cstdio>
#include <cmath>
double calc(double L,double A)
{
    double l=L/2,r=1e10;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2;
        double theta=asin(L/2/mid);
        double now=mid*theta*2;
        if (now<A)
            r=mid;
        else
            l=mid;
    }
    double R=(l+r)/2;
    double h=sqrt(R*R-L*L/4);
    return(R-h);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double L,n,C;
        scanf("%lf%lf%lf",&L,&n,&C);
        double A=(1+n*C)*L;
        static int id=0;
        printf("Case %d: ",++id);
        if (fabs(L-A)<1e-8)
            printf("0\n");
        else
            printf("%.10f\n",calc(L,A));
    }
    return(0);
}

