#include <cstdio>
#include <cstring>
const int mod=10007;
int fac[510],s[510][510];
void init()
{
    fac[0]=s[0][0]=1;
    for (int i=1;i<=500;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        for (int j=1;j<=i;j++)
            s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%mod;
    }
}
int K,b[50010],f[50010][510],a[100010][2];
void dp(int x,int father)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        for (int j=0;j<=K;j++)
        {
            f[x][j]=(f[x][j]+f[y][j])%mod;
            if (j>0)
                f[x][j]=(f[x][j]+f[y][j-1])%mod;
            if (j<=1)
                f[x][j]=(f[x][j]+1)%mod;
        }
    }
}
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        memcpy(f[0],f[x],sizeof(f[x]));
        for (int j=0;j<=K;j++)
        {
            f[0][j]=(f[0][j]-f[y][j])%mod;
            if (j>0)
                f[0][j]=(f[0][j]-f[y][j-1])%mod;
            if (j<=1)
                f[0][j]=(f[0][j]-1)%mod;
        }
        for (int j=0;j<=K;j++)
        {
            f[y][j]=(f[y][j]+f[0][j])%mod;
            if (j>0)
                f[y][j]=(f[y][j]+f[0][j-1])%mod;
            if (j<=1)
                f[y][j]=(f[y][j]+1)%mod;
        }
        dfs(y,x);
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(b,0,sizeof(b));
        int n;
        scanf("%d%d",&n,&K);
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        memset(f,0,sizeof(f));
        dp(1,0);
        dfs(1,0);
        for (int i=1;i<=n;i++)
        {
            int ans=0;
            for (int j=0;j<=K;j++)
                ans=(ans+s[K][j]*fac[j]%mod*f[i][j])%mod;
            printf("%d\n",(ans+mod)%mod);
        }
    }
    return(0);
}

