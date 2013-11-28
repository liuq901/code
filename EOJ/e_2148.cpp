#include <cstdio>
#include <cstring>
#include <cctype>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[1010][1010];
bool vis[1010][1010];
int n,m;
void dfs(int x0,int y0)
{
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=1 && x<=n && y>=1 && y<=m && a[x0][y0]==a[x][y] && !vis[x][y])
            dfs(x,y);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (isalnum(a[i][j]) && a[i][j]!='0' && !vis[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
    return(0);
}

