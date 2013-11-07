#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[30][1010],b[30][1010],f[30][1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d%d",&b[i][j],&a[i][j]);
        memset(f,63,sizeof(f));
        f[0][1]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                for (int k=1;k<=m;k++)
                    f[i][j]=min(f[i][j],f[i-1][k]+abs(b[i][j]-b[i-1][k]));
                f[i][j]+=a[i][j];
            }
        int ans=1<<30;
        for (int i=1;i<=m;i++)
            ans=min(ans,f[n][i]+K-b[n][i]);
        printf("%d\n",ans);
    }
    return(0);
}

