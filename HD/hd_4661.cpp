#include <cstdio>
typedef long long ll;
const int N=1000010,mod=1000000007;
int fac[N],inv[N];
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
void init()
{
    fac[0]=inv[0]=1;
    for (int i=1;i<=1000000;i++)
    {
        fac[i]=ll(fac[i-1])*i%mod;
        inv[i]=power(fac[i],mod-2);
    }
}
int up[N],cnt[N],f[N],q[N],fa[N],b[N],a[N*2][2];
int bfs(int n)
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (y==fa[x])
                continue;
            fa[y]=x;
            q[++r]=y;
        }
    }
    for (int i=n;i;i--)
    {
        int x=q[i];
        cnt[x]=0;
        f[x]=1;
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (y==fa[x])
                continue;
            f[x]=ll(f[x])*f[y]%mod*inv[cnt[y]+1]%mod;
            cnt[x]+=cnt[y]+1;
        }
        f[x]=ll(f[x])*fac[cnt[x]]%mod;
    }
    up[1]=1;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int x=q[i];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (y==fa[x])
                continue;
            int now=ll(f[x])*power(f[y],mod-2)%mod*fac[cnt[y]+1]%mod*inv[cnt[x]]%mod;
            up[y]=ll(up[x])*now%mod*fac[n-1-cnt[y]-1]%mod*inv[n-1-cnt[x]]%mod;
        }
        int tmp=ll(f[x])*up[x]%mod*fac[n-1]%mod*inv[cnt[x]]%mod*inv[n-1-cnt[x]]%mod;
        ans=(ans+ll(tmp)*tmp)%mod;
    }
    return(ans);
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
        for (int i=1;i<=n;i++)
            b[i]=0;
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        printf("%d\n",bfs(n));
    }
    return(0);
}

