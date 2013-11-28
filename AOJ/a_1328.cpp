#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double *a[10],b[10],ans[10],f[10],c[10][10];
int n;
bool gauss(int u,int v)
{
    int m=0;
    for (int i=0;i<=n+2;i++)
    {
        if (i==u || i==v)
            continue;
        double x=1;
        m++;
        for (int j=1;j<=n+1;j++)
        {
            c[m][j]=x;
            x*=i;
        }
        b[m]=f[i];
    }
    for (int i=1;i<=m;i++)
        a[i]=c[i];
    for (int i=1;i<=m;i++)
    {
        for (int j=i;j<=m;j++)
            if (fabs(a[j][i])>fabs(a[i][i]))
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        if (fabs(a[i][i])<1e-8)
            return(false);
        for (int j=1;j<=m;j++)
        {
            if (i==j)
                continue;
            double p=a[j][i]/a[i][i];
            for (int k=i;k<=m;k++)
                a[j][k]-=a[i][k]*p;
            b[j]-=b[i]*p;
        }
    }
    for (int i=1;i<=m;i++)
        ans[i-1]=b[i]/a[i][i];
    return(true);
}
double calc(int x)
{
    double p=1,ret=0;
    for (int i=0;i<=n;i++)
    {
        ret+=ans[i]*p;
        p*=x;
    }
    return(ret);
}
int check()
{
    int ret=0;
    for (int i=0;i<=n+2;i++)
        ret+=fabs(calc(i)-f[i])<1e-2;
    return(ret);
}
int getans()
{
    for (int i=0;i<=n+2;i++)
        if (fabs(calc(i)-f[i])>1e-2)
            return(i);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=0;i<=n+2;i++)
            scanf("%lf",&f[i]);
        for (int i=0;i<=n+2;i++)
            for (int j=i+1;j<=n+2;j++)
                if (gauss(i,j) && check()==n+2)
                {
                    printf("%d\n",getans());
                    goto out;
                }
out:
        ;
    }
    return(0);
}

