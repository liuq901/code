#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[4010],b[4010],f[4010][4010];
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    memset(f,63,sizeof(f));
    int inf=f[0][0],ans=0;
    f[0][0]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<=K;j++)
        {
            if (f[i][j]==inf)
                continue;
            f[i+1][j]=min(f[i+1][j],max(f[i][j]+1,a[i+1])+b[i+1]-1);
            if (j<K)
                f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
            ans=max(ans,a[i+1]-f[i][j]-1);
        }
    for (int i=0;i<=K;i++)
        ans=max(ans,86400-f[n][i]);
    printf("%d\n",ans);
    return(0);
}

