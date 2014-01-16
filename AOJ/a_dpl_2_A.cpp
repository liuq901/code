#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1000000000;
int b[20],f[66000][20],a[1000000][3];
int tsp(int n)
{
    memset(f,63,sizeof(f));
    for (int i=b[1];i;i=a[i][2])
    {
        int x=a[i][0];
        f[1<<x-1][x]=a[i][1];
    }
    for (int i=0;i<1<<n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (f[i][j]>=inf)
                continue;
            for (int k=b[j];k;k=a[k][2])
            {
                int x=a[k][0];
                if (i>>x-1&1)
                    continue;
                f[i^1<<x-1][x]=min(f[i^1<<x-1][x],f[i][j]+a[k][1]);
            }
        }
    }
    return(f[(1<<n)-1][1]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
    }
    int ans=tsp(n);
    if (ans>=inf)
        ans=-1;
    printf("%d\n",ans);
    return(0);
}

