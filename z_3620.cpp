#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int v[20],a[20][20],f[1100][20];
int main()
{
    int n,m,T;
    while (scanf("%d%d%d",&n,&m,&T)==3)
    {
        int begin,end;
        scanf("%d%d",&begin,&end);
        for (int i=0;i<n;i++)
            scanf("%d",&v[i]);
        memset(a,63,sizeof(a));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=min(a[x][y],z);
            a[y][x]=min(a[y][x],z);
        }
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        memset(f,63,sizeof(f));
        int inf=f[0][0];
        f[1<<begin][begin]=0;
        for (int i=0;i<1<<n;i++)
            for (int j=0;j<n;j++)
            {
                if (f[i][j]==inf)
                    continue;
                for (int k=0;k<n;k++)
                {
                    if (i>>k&1)
                        continue;
                    f[i|1<<k][k]=min(f[i|1<<k][k],f[i][j]+a[j][k]);
                }
            }
        int ans=0;
        for (int i=0;i<1<<n;i++)
            if (f[i][end]<=T)
            {
                int now=0;
                for (int j=0;j<n;j++)
                    if (i>>j&1)
                        now+=v[j];
                ans=max(ans,now);
            }
        printf("%d\n",ans);
    }
    return(0);
}

