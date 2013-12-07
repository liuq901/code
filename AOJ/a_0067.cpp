#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[20][20];
char a[20][20];
void dfs(int x0,int y0)
{
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=1 && x<=12 && y>=1 && y<=12 && a[x][y]=='1' && !vis[x][y])
            dfs(x,y);
    }
}
int main()
{
    while (scanf("%s",a[1]+1)==1)
    {
        for (int i=2;i<=12;i++)
            scanf("%s",a[i]+1);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for (int i=1;i<=12;i++)
            for (int j=1;j<=12;j++)
                if (a[i][j]=='1' && !vis[i][j])
                {
                    ans++;
                    dfs(i,j);
                }
        printf("%d\n",ans);
    }
    return(0);
}

