#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool vis[1010][1010];
char a[1010][1010];
int d[1010][1010],f[1010][1010],q[1000010][2];
void work()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int l=1,r=0;
    memset(d,63,sizeof(d));
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='F')
            {
                q[++r][0]=i,q[r][1]=j;
                vis[i][j]=true;
                d[i][j]=0;
            }
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x<=0 || x>n || y<=0 || y>m || vis[x][y] || a[x][y]=='#')
                continue;
            vis[x][y]=true;
            d[x][y]=d[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
        }
    }
    memset(vis,0,sizeof(vis));
    l=1,r=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='J')
            {
                q[++r][0]=i,q[r][1]=j;
                vis[i][j]=true;
                f[i][j]=0;
            }
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x<=0 || x>n || y<=0 || y>m || vis[x][y] || a[x][y]=='#' || d[x][y]<=f[x0][y0]+1)
                continue;
            vis[x][y]=true;
            f[x][y]=f[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
        }
    }
    int ans=-1;
    for (int i=1;i<=n;i++)
    {
        if (vis[i][1] && (ans==-1 || f[i][1]<ans))
            ans=f[i][1];
        if (vis[i][m] && (ans==-1 || f[i][m]<ans))
            ans=f[i][m];
    }
    for (int i=1;i<=m;i++)
    {
        if (vis[1][i] && (ans==-1 || f[1][i]<ans))
            ans=f[1][i];
        if (vis[n][i] && (ans==-1 || f[n][i]<ans))
            ans=f[n][i];
    }
    if (ans==-1)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n",ans+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        work();
    return(0);
}

