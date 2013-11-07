#include <cstdio>
#include <cstring>
const int mod=20090517;
int a[1010],f[1010][1010];
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
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
            f[i][i]=1;
        for (int i=n;i;i--)
            for (int j=i+1;j<=n;j++)
            {
                int pos=n-j+i;
                if (a[pos]!=0)
                {
                    if (a[pos]==i)
                        f[i][j]=f[i+1][j];
                    if (a[pos]==j)
                        f[i][j]=f[i][j-1];
                    continue;
                }
                f[i][j]=(f[i+1][j]+f[i][j-1])%mod;
            }
        printf("%d\n",f[1][n]);
    }
    return(0);
}

