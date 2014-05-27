#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,cnt[10010],v[10010],b[10010],a[10010][2];
bool vis[10010];
void dfs(int x)
{
    cnt[x]=1;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        dfs(y);
        v[x]+=v[y];
        cnt[x]+=cnt[y];
    }
    ans+=abs(v[x]-cnt[x]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,tot=0;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            int K;
            scanf("%d%d",&v[x],&K);
            for (int j=1;j<=K;j++)
            {
                int y;
                scanf("%d",&y);
                vis[y]=true;
                a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
            }
        }
        int root;
        for (int i=1;i<=n;i++)
            if (!vis[i])
            {
                root=i;
                break;
            }
        ans=0;
        dfs(root);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

