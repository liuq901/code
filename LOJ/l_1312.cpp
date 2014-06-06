#include <cstdio>
const int mod=10007;
int b[10010],a[10010][2],f[10010][2],g[10010][2];
void get(int x,int &ans,int &cnt)
{
    if (f[x][0]>f[x][1])
        ans=f[x][0],cnt=g[x][0];
    else if (f[x][1]>f[x][0])
        ans=f[x][1],cnt=g[x][1];
    else
        ans=f[x][0],cnt=(g[x][0]+g[x][1])%mod;
}
void dp(int x)
{
    f[x][0]=0,g[x][0]=1;
    f[x][1]=-1<<30,g[x][1]=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        dp(y);
        int ans,cnt;
        get(y,ans,cnt);
        if (f[x][0]+f[y][0]+1>f[x][1]+ans)
        {
            f[x][1]=f[x][0]+f[y][0]+1;
            g[x][1]=g[x][0]*g[y][0]%mod;
        }
        else if (f[x][1]+ans>f[x][0]+f[y][0]+1)
        {
            f[x][1]=f[x][1]+ans;
            g[x][1]=g[x][1]*cnt%mod;
        }
        else
        {
            f[x][1]=f[x][1]+ans;
            g[x][1]=(g[x][0]*g[y][0]+g[x][1]*cnt)%mod;
        }
        f[x][0]+=ans;
        g[x][0]=g[x][0]*cnt%mod;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,tot=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,K;
            scanf("%d%d",&x,&K);
            b[x]=0;
            for (int j=1;j<=K;j++)
            {
                int y;
                scanf("%d",&y);
                a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
            }
        }
        dp(1);
        static int id=0;
        printf("Case %d: ",++id);
        int ans,cnt;
        get(1,ans,cnt);
        printf("%d %d\n",ans,cnt);
    }
    return(0);
}

