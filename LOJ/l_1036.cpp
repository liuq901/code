#include <cstdio>
#include <algorithm>
using namespace std;
int a[510][510],b[510][510],l[510][510],u[510][510],f[510][510];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                l[i][j]=l[i][j-1]+a[i][j];
                u[i][j]=u[i-1][j]+b[i][j];
                f[i][j]=max(f[i][j-1]+u[i][j],f[i-1][j]+l[i][j]);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][m]);
    }
    return(0);
}

