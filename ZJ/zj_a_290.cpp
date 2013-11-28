#include <cstdio>
#include <cstring>
int b[810],a[1000010][2];
bool vis[810];
bool dfs(int x,int T)
{
    if (x==T)
        return(true);
    if (vis[x])
        return(false);
    vis[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (dfs(y,T))
            return(true);
    }
    return(false);
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
        }
        int S,T;
        scanf("%d%d",&S,&T);
        memset(vis,0,sizeof(vis));
        printf("%s!!!\n",dfs(S,T)?"Yes":"No");
    }
    return(0);
}

