#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        double x;
        scanf("%*lf%lf",&x);
        sum+=x;
    }
    printf("%.10f\n",5+sum/n);
    return(0);
}

