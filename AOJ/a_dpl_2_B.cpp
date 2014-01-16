#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[20],a[20][20],f[66000];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,63,sizeof(a));
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        ans+=z;
        x++,y++;
        a[x][y]=min(a[x][y],z);
        a[y][x]=min(a[y][x],z);
        d[x]++,d[y]++;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    int mask=0;
    for (int i=1;i<=n;i++)
        if (d[i]%2==0)
            mask^=1<<i-1;
    memset(f,63,sizeof(f));
    f[mask]=0;
    for (int i=mask;i<1<<n;i++)
    {
        if (f[i]>=1000000000)
            continue;
        for (int j=1;j<=n;j++)
        {
            if (i>>j-1&1)
                continue;
            for (int k=1;k<=n;k++)
            {
                if (i>>k-1&1)
                    continue;
                f[i^1<<j-1^1<<k-1]=min(f[i^1<<j-1^1<<k-1],f[i]+a[j][k]);
            }
        }
    }
    printf("%d\n",ans+f[(1<<n)-1]);
    return(0);
}

