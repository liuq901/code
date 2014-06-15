#include <cstdio>
#include <cstring>
int to[1010],b[1010],a[10010][2];
bool vis[1010];
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
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
        }
        memset(to,0,sizeof(to));
        int ans=n;
        for (int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            ans-=hungary(i);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

