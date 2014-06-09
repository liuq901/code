#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int ans[60][60],f[2][60][60][60];
void init()
{
    const int n=50;
    f[1][1][1][1]=1;
    for (int i=1;i<=n;i++)
    {
        int u=i&1,v=u^1;
        for (int j=1;j<=i;j++)
            for (int k=1;k<=i;k++)
                for (int l=1;l<=k;l++)
                {
                    if (f[u][j][k][l]==0)
                        continue;
                    ans[i][k]=(ans[i][k]+f[u][j][k][l])%mod;
                    for (int p=1;p<=i+1;p++)
                    {
                        int len=p<=j?1:l+1,ma=max(len,k);
                        f[v][p][ma][len]=(f[v][p][ma][len]+f[u][j][k][l])%mod;
                    }
                    f[u][j][k][l]=0;
                }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        static int id=0;
        printf("Case %d: %d\n",++id,ans[n][m]);
    }
    return(0);
}

