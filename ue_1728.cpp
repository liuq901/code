#include <cstdio>
#include <cstring>
int no,b[10010],a[200010][2];
bool vis[10010];
bool dfs(int x,int father)
{
    vis[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father || y==no)
            continue;
        if (vis[y])
            return(false);
        if (!dfs(y,x))
            return(false);
    }
    return(true);
}
int main()
{
    int n,m;
    while (scanf("%d%d%d",&n,&m,&no)==3)
    {
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(vis,0,sizeof(vis));
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            if (i==no || vis[i])
                continue;
            if (!dfs(i,0))
            {
                flag=false;
                break;
            }
        }
        printf("%s\n",flag?"I won't let you go":"Don't worry.Be happy");
    }
    return(0);
}

