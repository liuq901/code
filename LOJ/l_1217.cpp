#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010],f[1010][2],g[1010][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        f[1][0]=0;
        g[1][1]=a[1];
        for (int i=2;i<=n;i++)
            for (int j=0;j<2;j++)
            {
                f[i][j]=max(f[i-1][j],g[i-1][j]);
                g[i][j]=f[i-1][j]+a[i];
            }
        static int id=0;
        printf("Case %d: %d\n",++id,max(max(f[n][0],g[n][0]),f[n][1]));
    }
    return(0);
}

