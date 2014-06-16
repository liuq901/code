#include <cstdio>
#include <cstring>
const int mod=1000000007;
char a[110],b[110],c[110];
int n,m,K,f[110][110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s%s",a+1,b+1,c+1);
        n=strlen(a+1),m=strlen(b+1),K=strlen(c+1);
        memset(f,0,sizeof(f));
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
                for (int k=0;k<=K;k++)
                {
                    if (i==0 && j==0 && k==0)
                    {
                        f[i][j][k]=1;
                        continue;
                    }
                    if (i)
                        f[i][j][k]=(f[i][j][k]+f[i-1][j][k])%mod;
                    if (j)
                        f[i][j][k]=(f[i][j][k]+f[i][j-1][k])%mod;
                    if (i && j)
                        f[i][j][k]=(f[i][j][k]-f[i-1][j-1][k]+mod)%mod;
                    if (i && k && a[i]==c[k])
                    {
                        f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1])%mod;
                        if (j)
                            f[i][j][k]=(f[i][j][k]-f[i-1][j-1][k-1]+mod)%mod;
                    }
                    if (j && k && b[j]==c[k])
                    {
                        f[i][j][k]=(f[i][j][k]+f[i][j-1][k-1])%mod;
                        if (i)
                            f[i][j][k]=(f[i][j][k]-f[i-1][j-1][k-1]+mod)%mod;
                    }
                }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][m][K]);
    }
    return(0);
}

