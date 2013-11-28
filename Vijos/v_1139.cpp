#include <cstdio>
int a[110][510],pre[110][510],f[110][510];
void print(int n,int m)
{
    if (n>1 && pre[n][m]==0)
        print(n-1,m);
    if (n>1 && pre[n][m]!=0)
        print(n,m+pre[n][m]);
    printf("%d\n",m);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=m;i++)
        f[1][i]=a[1][i];
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            f[i][j]=f[i-1][j]+a[i][j];
            pre[i][j]=0;
        }
        for (int j=2;j<=m;j++)
            if (f[i][j-1]+a[i][j]<f[i][j])
            {
                f[i][j]=f[i][j-1]+a[i][j];
                pre[i][j]=-1;
            }
        for (int j=m-1;j;j--)
            if (f[i][j+1]+a[i][j]<f[i][j])
            {
                f[i][j]=f[i][j+1]+a[i][j];
                pre[i][j]=1;
            }
    }
    int k=1;
    for (int i=1;i<=m;i++)
        if (f[n][i]<f[n][k])
            k=i;
    print(n,k);
    return(0);
}

