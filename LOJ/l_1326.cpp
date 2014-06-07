#include <cstdio>
const int mod=10056;
int ans[1010],f[1010][1010];
void init()
{
    const int n=1000;
    ans[1]=f[1][1]=1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=i;j++)
        {
            f[i][j]=(f[i-1][j]+f[i-1][j-1])*j%mod;
            ans[i]=(ans[i]+f[i][j])%mod;
        }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("Case %d: %d\n",++id,ans[n]);
    }
    return(0);
}

