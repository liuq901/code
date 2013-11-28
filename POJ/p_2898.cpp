#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[1010][1010];
vector <char> b[1010];
int tot,len[1010],vis[1010][1010];
void dfs(int x0,int y0)
{
    vis[x0][y0]=tot;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (a[x][y]==a[x0][y0] && vis[x][y]!=tot)
            dfs(x,y);
    }
}
int main()
{
    while (scanf("%s",a[1]+1)==1)
    {
        int n=1;
        while (1)
        {
            n++;
            scanf("%s",a[n]+1);
            if (!islower(a[n][1]))
                break;
        }
        int Q;
        sscanf(a[n]+1,"%d",&Q);
        n--;
        for (int i=1;i<=n;i++)
            len[i]=strlen(a[i]+1);
        memset(vis,0,sizeof(vis));
        tot=0;
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            tot++;
            if (a[x][y]==' ')
                continue;
            dfs(x,y);
            int m=0;
            for (int i=1;i<=len[n];i++)
                b[i].clear();
            for (int i=1;i<=n;i++)
            {
                int now=0;
                for (int j=1;j<=len[i];j++)
                {
                    if (vis[i][j]!=tot)
                    {
                        b[++now].push_back(a[i][j]);
                        m=max(m,now);
                    }
                    a[i][j]=' ';
                }
            }
            n=b[1].size();
            for (int i=1;i<=m;i++)
            {
                reverse(b[i].begin(),b[i].end());
                for (int j=0;j<b[i].size();j++)
                {
                    a[n-j][i]=b[i][j];
                    len[n-j]=i;
                }
            }
        }
        static int id=0;
        printf("Test case #%d:\n",++id);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=len[i];j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
        memset(a,0,sizeof(a));
    }
    return(0);
}

