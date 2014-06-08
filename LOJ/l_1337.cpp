#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,idx,tot,ans[1010],vis[510][510];
char a[510][510];
void dfs(int x0,int y0)
{
    vis[x0][y0]=idx;
    tot+=a[x0][y0]=='C';
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]!='#' && !vis[x][y])
            dfs(x,y);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Q;
        scanf("%d%d%d",&n,&m,&Q);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(vis,0,sizeof(vis));
        idx=0;
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (vis[x][y]==0)
            {
                idx++;
                tot=0;
                dfs(x,y);
                ans[idx]=tot;
            }
            printf("%d\n",ans[vis[x][y]]);
        }
    }
    return(0);
}

