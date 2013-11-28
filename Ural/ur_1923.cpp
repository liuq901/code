#include <cstdio>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[60][60];
int n,m;
void dfs(char ch,int x0,int y0,char change)
{
    a[x0][y0]=change;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]==ch)
            dfs(ch,x,y,change);
    }
}
bool vis[60][60];
int getans(int x0,int y0)
{
    int ret=1;
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]==a[x0][y0] && !vis[x][y])
            ret+=getans(x,y);
    }
    return(ret);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int K;
    scanf("%d",&K);
    for (int i=1;i<=K;i++)
    {
        int x;
        scanf("%d",&x);
        if (i&1)
            dfs(a[n][1],n,1,x+'0');
        else
            dfs(a[1][m],1,m,x+'0');
    }
    printf("%d\n%d\n",getans(n,1),getans(1,m));
    return(0);
}

