#include <cstdio>
char a[1010][1010];
bool vis[1010][1010];
int work(int n,int m)
{
    int ret=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='#' && !vis[i][j])
            {
                ret++;
                int x=i,y=j;
                while (x<=n && a[x][j]=='#')
                    x++;
                while (y<=m && a[i][y]=='#')
                    y++;
                for (int u=i;u<x;u++)
                    for (int v=j;v<y;v++)
                    {
                        if (a[u][v]!='#' || vis[u][v])
                            return(-1);
                        vis[u][v]=true;
                    }
            }
    return(ret);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int ans=work(n,m);
    if (ans==-1)
        printf("Bad placement.\n");
    else
        printf("There are %d ships.\n",ans);
    return(0);
}

