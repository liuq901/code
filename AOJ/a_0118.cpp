#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[110][110];
bool vis[110][110];
int n,m;
void dfs(int x0,int y0)
{
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>0 && x<=n && y>0 && y<=m && !vis[x][y] && a[x][y]==a[x0][y0])
            dfs(x,y);
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int ans=0;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (!vis[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
    return(0);
}

