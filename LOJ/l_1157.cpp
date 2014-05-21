#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=1000007;
int f[1010][1010],g[1010][1010];
char a[1010],b[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        for (int i=1;i<=n;i++)
            g[i][0]=1;
        for (int i=1;i<=m;i++)
            g[0][i]=1;
        g[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i]==b[j])
                {
                    f[i][j]=f[i-1][j-1]+1;
                    g[i][j]=g[i-1][j-1];
                    continue;
                }
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                g[i][j]=0;
                if (f[i][j]==f[i-1][j])
                    g[i][j]+=g[i-1][j];
                if (f[i][j]==f[i][j-1])
                    g[i][j]+=g[i][j-1];
                if (f[i][j]==f[i-1][j-1])
                    g[i][j]-=g[i-1][j-1];
                g[i][j]=(g[i][j]+mod)%mod;
            }
        static int id=0;
        printf("Case %d: %d\n",++id,g[n][m]);
    }
    return(0);
}

