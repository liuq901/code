#include <cstdio>
int a[150][150];
int main()
{
    int n;
    scanf("%d",&n);
    int m=1;
    while (m*(m-1)/2<=n)
        m++;
    m--;
    printf("%d\n",m);
    int t=0;
    for (int i=1;i<=m;i++)
    {
        for (int j=i+1;j<=m;j++)
            a[i][j]=a[j][i]=++t;
        bool first=true;
        for (int j=1;j<=m;j++)
        {
            if (i==j)
                continue;
            if (!first)
                printf(" ");
            first=false;
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return(0);
}

