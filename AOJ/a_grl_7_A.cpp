#include <cstdio>
#include <cstring>
bool vis[110];
int b[110],to[110],a[10010][2];
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
    int n,m;
    scanf("%d%*d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans+=hungary(i);
    }
    printf("%d\n",ans);
    return(0);
}

