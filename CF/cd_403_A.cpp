#include <cstdio>
#include <cstring>
char a[30][30];
int n,tot,limit;
bool vis[30];
void dfs(int x,int dep)
{
    int y=x+dep;
    if (y>n)
        y-=n;
    if (vis[y] || a[x][y])
        return;
    vis[y]=true;
    a[x][y]=a[y][x]=true;
    tot++;
    if (tot==limit)
        return;
    dfs(y,dep);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int p;
        scanf("%d%d",&n,&p);
        tot=0;
        limit=2*n+p;
        memset(a,0,sizeof(a));
        for (int i=1;;i++)
        {
            memset(vis,0,sizeof(vis));
            for (int j=1;j<=n;j++)
                if (!vis[j])
                {
                    dfs(j,i);
                    if (tot==limit)
                        break;
                }
            if (tot==limit)
                break;
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (a[i][j])
                    printf("%d %d\n",i,j);
    }
    return(0);
}

