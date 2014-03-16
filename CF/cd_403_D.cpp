#include <cstdio>
typedef long long ll;
typedef int array[1010][1010];
const int mod=1000000007;
array sum,s,div,ans;
int fac[1010];
void init()
{
    int n=1000;
    fac[0]=1;
    for (int i=1;i<=n;i++)
        fac[i]=ll(fac[i-1])*i%mod;
    for (int i=0;i<=n;i++)
        sum[1][i]=1;
    for (int i=2;i<=n;i++)
    {
        sum[i][i-1]=sum[i-1][0];
        for (int j=i;j<=n;j++)
            sum[i][j]=(sum[i-1][j-i+1]+sum[i][j-i])%mod;
    }
    div[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        div[1][i]=1;
        s[1][i]=(div[1][i]+s[1][i-1])%mod;
    }
    for (int i=2;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            div[i][j]=s[i-1][j-1];
            s[i][j]=(div[i][j]+s[i][j-1])%mod;
        }
    int tot=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            if (sum[i][j]==0)
                continue;
            ll tmp=ll(sum[i][j])*fac[i]%mod;
            for (int k=i-1;k<=n-j;k++)
                ans[i][j+k]=(ans[i][j+k]+tmp*div[i-1][k])%mod;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            ans[i][j]=(ans[i][j]+ans[i][j-1])%mod;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            ans[i][j]=(ans[i][j]+ans[i][j-1])%mod;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        printf("%d\n",ans[K][n-1]);
    }
    return(0);
}

