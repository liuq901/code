#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=100000007;
int s[15010],ss[15010],f[2][15010];
void calc(int f[],int m)
{
    s[0]=ss[0]=f[0];
    for (int i=1;i<=m;i++)
    {
        s[i]=(s[i-1]+f[i])%mod;
        ss[i]=(ss[i-1]+s[i])%mod;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K,m;
        scanf("%d%d%d",&n,&K,&m);
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            int u=i&1,v=u^1;
            calc(f[v],m);
            f[u][0]=0;
            for (int j=1;j<=m;j++)
                if (j<=K)
                    f[u][j]=ss[j-1];
                else
                    f[u][j]=((ss[j-1]-ss[j-K-1]-ll(s[j-K-1])*K)%mod+mod)%mod;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n&1][m]);
    }
    return(0);
}

