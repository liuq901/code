#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int a[20],t[20],f[20][110],c[110][110];
int calc(int n)
{
    memset(f,0,sizeof(f));
    for (int i=a[0];i<=n;i++)
        f[0][i]=c[n][i];
    for (int i=1;i<10;i++)
        for (int j=0;j<=n-a[i];j++)
            for (int k=j+a[i];k<=n;k++)
                f[i][k]=(f[i][k]+ll(f[i-1][j])*c[n-j][k-j])%mod;
    int ret=0;
    for (int i=0;i<=n;i++)
        ret=(ret+f[9][i])%mod;
    return(f[9][n]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for (int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        t[i]=a[i];
    }
    int ans=0;
    for (int i=1;i<10;i++)
    {
        a[i]=max(0,a[i]-1);
        for (int j=1;j<=n;j++)
            ans=(ans+calc(j-1))%mod;
        a[i]=t[i];
    }
    printf("%d\n",ans);
    return(0);
}

