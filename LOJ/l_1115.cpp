#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[60][60];
bool flag[26],vis[60][60];
int n,m;
void dfs(int x0,int y0,char ch)
{
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>0 && x<=n && y>0 && y<=m && !vis[x][y] && a[x][y]!=ch)
            dfs(x,y,ch);
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
        memset(flag,0,sizeof(flag));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='.' || flag[a[i][j]-'A'])
                    continue;
                flag[a[i][j]-'A']=true;
                memset(vis,0,sizeof(vis));
                for (int k=1;k<=n;k++)
                {
                    if (!vis[k][1] && a[k][1]!=a[i][j])
                        dfs(k,1,a[i][j]);
                    if (!vis[k][m] && a[k][m]!=a[i][j])
                        dfs(k,m,a[i][j]);
                }
                for (int k=1;k<=m;k++)
                {
                    if (!vis[1][k] && a[1][k]!=a[i][j])
                        dfs(1,k,a[i][j]);
                    if (!vis[n][k] && a[n][k]!=a[i][j])
                        dfs(n,k,a[i][j]);
                }
                for (int k=1;k<=n;k++)
                    for (int l=1;l<=m;l++)
                        if (!vis[k][l])
                            a[k][l]=a[i][j];
            }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%s\n",a[i]+1);
    }
    return(0);
}

