#include <cstdio>
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
char a[110][110];
int n,m;
void dfs(int x0,int y0)
{
    a[x0][y0]='.';
    for (int i=0;i<8;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (a[x][y]=='W')
            dfs(x,y);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='W')
            {
                ans++;
                dfs(i,j);
            }
    printf("%d\n",ans);
    return(0);
}

