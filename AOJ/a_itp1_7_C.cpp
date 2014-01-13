#include <cstdio>
int a[1010][1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][m+1]+=a[i][j];
            a[n+1][j]+=a[i][j];
            a[n+1][m+1]+=a[i][j];
        }
    for (int i=1;i<=n+1;i++)
        for (int j=1;j<=m+1;j++)
            printf("%d%c",a[i][j],j==m+1?'\n':' ');
    return(0);
}

