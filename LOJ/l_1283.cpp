#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110],f[110][110][110];
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
        a[0]=-1<<30;
        a[n+1]=1<<30;
        memset(f,-63,sizeof(f));
        f[0][0][n+1]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=n+1;j++)
                for (int k=0;k<=n+1;k++)
                {
                    f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
                    if (f[i-1][j][k]<0 || a[j]>a[i] || a[i]>a[k])
                        continue;
                    f[i][i][k]=max(f[i][i][k],f[i-1][j][k]+1);
                    f[i][j][i]=max(f[i][j][i],f[i-1][j][k]+1);
                }
        int ans=0;
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=n+1;j++)
                ans=max(ans,f[n][i][j]);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

