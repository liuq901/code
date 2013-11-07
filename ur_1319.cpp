#include <cstdio>
int a[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    int t=0;
    for (int i=1-n;i<=n-1;i++)
        for (int j=1;j<=n;j++)
        {
            int k=j-i;
            if (k>0 && k<=n)
                a[j][k]=++t;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            printf("%d%c",a[i][j],j==n?'\n':' ');
    return(0);
}

