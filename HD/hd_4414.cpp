#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,len[60][60];
char a[60][60];
bool vis[60][60];
void work(int x0,int y0)
{
    int d[10]={0};
    for (int i=0;i<4;i++)
    {
        int x=x0,y=y0;
        while (1)
        {
            x+=c[i][0],y+=c[i][1];
            if (x==0 || x>n || y==0 || y>n || a[x][y]!='#')
                break;
            d[i]++;
        }
    }
    for (int i=0;i<4;i++)
        if (d[i]!=d[0])
            return;
    len[x0][y0]=d[0];
}
int dfs(int x0,int y0)
{
    int ret=1;
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x==0 || x>n || y==0 || y>n || a[x][y]!='#' || vis[x][y])
            continue;
        ret+=dfs(x,y);
    }
    return(ret);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(len,0,sizeof(len));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (a[i][j]=='#')
                    work(i,j);
        int ans=0;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (len[i][j]!=0)
                    if (dfs(i,j)==len[i][j]*4+1)
                        ans++;
        printf("%d\n",ans);
    }
    return(0);
}

