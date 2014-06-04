#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007;
int p[510];
bool prime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return(false);
    return(true);
}
int a[510][510],f[510][510];
void init()
{
    int m=0,n=500;
    for (int i=2;;i++)
    {
        if (!prime(i))
            continue;
        p[++m]=i;
        if (m==n)
            break;
    }
    for (int i=1;i<=n;i++)
    {
        a[i][0]=1;
        for (int j=1;j<=n;j++)
            a[i][j]=ll(a[i][j-1])*p[i]%mod;
    }
    f[0][0]=1;
    for (int i=1;i<=m;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=j;k++)
                f[i][j]=(f[i][j]+ll(f[i-1][j-k])*a[i][k])%mod;    
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
        int ans=1;
        for (int i=1;i<=m;i++)
            ans=ll(ans)*(p[i]-1)%mod;
        n-=m;
        static int id=0;
        printf("Case %d: %d\n",++id,ll(ans)*f[m][n]%mod);
    }
    return(0);
}

