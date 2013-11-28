#include <cstdio>
#include <cmath>
double a[1000010],b[1000010];
double calc(int m,int n)
{
    a[n]=a[n+1]=b[n]=b[n+1]=0;
    for (int i=n-1;i;i--)
    {
        a[i]=(2*m-i-1.0)/m*a[i+1]-double(m-i)/m*a[i+2]+1.0/m;
        b[i]=(2*m-i-1.0)/m*b[i+1]-double(m-i)/m*b[i+2]+1;
    }
    double x=b[1]/(1-a[1]);
    return(a[1]*x+b[1]-a[2]*x-b[2]+1);
}
int main()
{
    int T;
    while (scanf("%d",&T)==1)
        while (T--)
        {
            int op,m,n;
            scanf("%d%d%d",&op,&m,&n);
            if (op==0)
                printf("%.10f\n",m==1?n:m/(m-1.0)*(pow(double(m),n-1.0)-1)+1);
            else
                printf("%.10f\n",calc(m,n));
        }
    return(0);
}

