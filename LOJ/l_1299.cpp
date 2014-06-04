#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007;
char a[1010];
int f[1010][1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n=strlen(a+1),tmp=0;
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=0;j<=i;j++)
                if (a[i]=='E')
                    f[i][j]=(f[i][j]+f[i-1][j])%mod;
                else if (a[i]=='D')
                {
                    f[i][j]=(f[i][j]+ll(f[i-1][j])*j)%mod;
                    if (j)
                        f[i][j-1]=(f[i][j-1]+ll(f[i-1][j])*j*j)%mod;
                }
                else
                {
                    if (j)
                        f[i][j]=(f[i][j]+f[i-1][j-1])%mod;
                    f[i][j]=(f[i][j]+ll(f[i-1][j])*j)%mod;
                }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][0]);
    }
    return(0);
}

