#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n*2;i++)
        printf(" ");
    printf("0\n");
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=(n-i)*2;j++)
            printf(" ");
        printf("0");
        for (int j=1;j<=i;j++)
            printf(" %d",j);
        for (int j=i-1;j;j--)
            printf(" %d",j);
        printf(" 0\n");
    }
    for (int i=n-1;i;i--)
    {
        for (int j=1;j<=(n-i)*2;j++)
            printf(" ");
        printf("0");
        for (int j=1;j<=i;j++)
            printf(" %d",j);
        for (int j=i-1;j;j--)
            printf(" %d",j);
        printf(" 0\n");
    }
    for (int i=1;i<=n*2;i++)
        printf(" ");
    printf("0\n");    
    return(0);
}

