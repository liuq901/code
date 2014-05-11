#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[20],a[20][20],f[32770];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        memset(a,63,sizeof(a));
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            d[x]++,d[y]++;
            ans+=z;
            a[x][y]=min(a[x][y],z);
            a[y][x]=min(a[y][x],z);
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        memset(f,63,sizeof(f));
        int inf=f[0],now=0;
        for (int i=1;i<=n;i++)
            if (d[i]%2==0)
                now|=1<<i-1;
        f[now]=ans;
        for (int i=0;i<1<<n;i++)
        {
            if (f[i]==inf)
                continue;
            for (int j=1;j<=n;j++)
            {
                if (i>>j-1&1)
                    continue;
                for (int k=j+1;k<=n;k++)
                {
                    if (i>>k-1&1)
                        continue;
                    f[i|1<<j-1|1<<k-1]=min(f[i|1<<j-1|1<<k-1],f[i]+a[j][k]);
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1]);
    }
    return(0);
}

