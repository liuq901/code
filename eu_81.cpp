#include <cstdio>
#include <algorithm>
using namespace std;
int a[100][100],f[100][100];
int main()
{
    int n=80;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d%*c",&a[i][j]);
    for (int i=1;i<=n;i++)
        f[i][0]=f[0][i]=1<<30;
    f[1][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
    printf("%d\n",f[n][n]);
    return(0);
}

