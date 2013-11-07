#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int mod;
ll c[5010],p[5010],g[2][5010],f[5010][5010];
int a[1000010];
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&mod);
    int L=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        L=max(L,a[i]);
    }
    c[0]=p[0]=f[0][0]=1;
    for (int i=1;i<=L;i++)
    {
        c[i]=c[i-1]*(m-i+1)%mod;
        p[i]=p[i-1]*i%mod;
        for (int j=1;j<=i;j++)
            f[i][j]=(f[i-1][j-1]+f[i-1][j]*(j-1))%mod;
    }
    ll ans=1;
    a[0]=0;
    for (int i=1;i<=n;i++)
    {
        int u=i&1,v=1-u;
        ll sum=0;
        for (int j=1;j<=min(m,a[i]);j++)
        {
            g[u][j]=f[a[i]][j]*(c[j]*ans%mod-p[j]*g[v][j]%mod)%mod;
            sum=(sum+g[u][j])%mod;
        }
        ans=sum;
        for (int j=1;j<=min(m,a[i-1]);j++)
            g[v][j]=0;
    }
    if (ans<0)
        ans+=mod;
    printf("%I64d\n",ans);
    return(0);
}

