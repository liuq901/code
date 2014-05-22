#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010][2],go[1010][2],f[1010][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i][0]);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i][1]);
        for (int i=1;i<n;i++)
            scanf("%d",&go[i][0]);
        for (int i=1;i<n;i++)
            scanf("%d",&go[i][1]);
        f[1][0]=a[1][0];
        f[1][1]=a[1][1];
        for (int i=1;i<n;i++)
            for (int j=0;j<2;j++)
                f[i+1][j]=min(f[i][j],f[i][j^1]+go[i][j^1])+a[i+1][j];
        static int id=0;
        printf("Case %d: %d\n",++id,min(f[n][0],f[n][1]));
    }
    return(0);
}

