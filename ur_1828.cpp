#include <cstdio>
double x[10010],y[10010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        x[i]=i;
        scanf("%lf",&y[i]);
    }
    double sumx,sumy,sumxy,sumx2;
    sumx=sumy=sumxy=sumx2=0;
    for (int i=1;i<=n;i++)
    {
        sumx+=x[i];
        sumy+=y[i];
        sumxy+=x[i]*y[i];
        sumx2+=x[i]*x[i];
    }
    double a=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    double b=sumy/n-a*sumx/n;
    printf("%.10f %.10f\n",a+b,a);
    return(0);
}

