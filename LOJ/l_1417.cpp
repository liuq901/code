#include <cstdio>
#include <cstring>
int tot,vis[50010],a[50010],d[50010],q[50010],f[50010],cnt[50010];
void dfs(int x)
{
    vis[x]=tot;
    cnt[tot]++;
    if (!vis[a[x]])
        dfs(a[x]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
            d[y]++;
        }
        int l=1,r=0;
        for (int i=1;i<=n;i++)
            if (d[i]==0)
                q[++r]=i;
        while (l<=r)
        {
            int x=q[l++],y=a[x];
            if (--d[y]==0)
                q[++r]=y;
        }
        memset(vis,0,sizeof(vis));
        tot=0;
        for (int i=1;i<=n;i++)
        {
            if (d[i]==0 || vis[i])
                continue;
            cnt[++tot]=0;
            dfs(i);
        }
        for (int i=1;i<=n;i++)
            if (d[i]!=0)
                f[i]=cnt[vis[i]];
        for (int i=r;i;i--)
        {
            int x=q[i],y=a[x];
            f[x]=f[y]+1;
        }
        int k=1;
        for (int i=1;i<=n;i++)
            if (f[i]>f[k])
                k=i;
        static int id=0;
        printf("Case %d: %d\n",++id,k);
    }
    return(0);
}

