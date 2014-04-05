#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(a,63,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=min(a[x][y],z);
            a[y][x]=min(a[y][x],z);
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        static int id=0;
        printf("Case %d: ",++id);
        if (a[1][n]==a[0][0])
            printf("Impossible\n");
        else
            printf("%d\n",a[1][n]);
    }
    return(0);
}

