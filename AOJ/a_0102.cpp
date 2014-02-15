#include <cstdio>
int a[1010][1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            a[i][n+1]=a[n+1][i]=0;
        a[n+1][n+1]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][n+1]+=a[i][j];
                a[n+1][j]+=a[i][j];
                a[n+1][n+1]+=a[i][j];
            }
        for (int i=1;i<=n+1;i++)
        {
            for (int j=1;j<=n+1;j++)
                printf("%5d",a[i][j]);
            printf("\n");
        }
    }
    return(0);
}

