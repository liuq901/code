#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
char a[110][110];
bool ans[30],use[30],vis[110][110];
bool dfs(int x0,int y0)
{
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x==0 || x>n || y==0 || y>m)
            return(false);
        if (a[x][y]!='.')
            use[a[x][y]-'A'+1]=true;
        if (a[x][y]=='.' && !vis[x][y] && !dfs(x,y))
            return(false);
    }
    return(true);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]=='.' && !vis[i][j])
                {
                    memset(use,0,sizeof(use));
                    if (dfs(i,j))
                    {
                        int cnt=0,p;
                        for (int k=1;k<=26;k++)
                            if (use[k])
                                cnt++,p=k;
                        if (cnt==1)
                            ans[p]=true;
                    }
                }
        for (int i=1;i<=26;i++)
            if (ans[i])
                printf("%c",i+'A'-1);
        printf("\n");
    }
    return(0);
}

