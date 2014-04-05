#include <cstdio>
#include <cstring>
typedef long long ll;
char a[40],b[40];
int f[40][40];
ll g[40][40];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a+1,b+1);
        int n=strlen(a+1),m=strlen(b+1);
        for (int i=1;i<=n;i++)
            f[i][0]=i,g[i][0]=1;
        for (int i=1;i<=m;i++)
            f[0][i]=i,g[0][i]=1;
        f[0][0]=0,g[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                f[i][j]=f[i-1][j]+1;
                g[i][j]=g[i-1][j];
                if (f[i][j-1]+1<f[i][j])
                {
                    f[i][j]=f[i][j-1]+1;
                    g[i][j]=g[i][j-1];
                }
                else if (f[i][j-1]+1==f[i][j])
                    g[i][j]+=g[i][j-1];
                if (a[i]!=b[j])
                    continue;
                f[i][j]=f[i-1][j-1]+1;
                g[i][j]=g[i-1][j-1];
            }
        static int id=0;
        printf("Case %d: %d %lld\n",++id,f[n][m],g[n][m]);
    }
    return(0);
}

