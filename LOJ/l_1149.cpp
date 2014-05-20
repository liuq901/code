#include <cstdio>
#include <cstring>
int tot,to[110],v[110],b[110],a[10010][2];
bool vis[110];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (vis[y])
            continue;
        vis[y]=true;
        if (hungary(to[y]))
        {
            to[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        tot=0;
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=1;j<=n;j++)
                if (x%v[j]==0)
                    add(j,i);
        }
        int ans=0;
        memset(to,0,sizeof(to));
        for (int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            ans+=hungary(i);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

