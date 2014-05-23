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
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[x][y]=a[y][x]=1;
        }
        for (int i=1;i<=n;i++)
            a[i][i]=0;
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        int S,T,ans=0;
        scanf("%d%d",&S,&T);
        S++,T++;
        for (int i=1;i<=n;i++)
            ans=max(ans,a[S][i]+a[i][T]);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

