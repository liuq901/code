#include <cstdio>
#include <cstring>
char a[110][110];
bool vis[110][110];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        memset(vis,0,sizeof(vis));
        int x=1,y=1;
        while (1)
        {
            if (vis[x][y])
            {
                printf("LOOP\n");
                break;
            }
            vis[x][y]=true;
            if (a[x][y]=='<')
                y--;
            else if (a[x][y]=='>')
                y++;
            else if (a[x][y]=='^')
                x--;
            else if (a[x][y]=='v')
                x++;
            else
            {
                printf("%d %d\n",y-1,x-1);
                break;
            }
        }
    }
    return(0);
}

