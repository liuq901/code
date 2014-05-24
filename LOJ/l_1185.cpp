#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[110],origin[110][110],a[110][110];
void dfs(int x,int n)
{
    for (int i=1;i<=n;i++)
        if (a[x][i] && !vis[i])
        {
            vis[i]=true;
            dfs(i,n);
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(origin,0,sizeof(origin));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            origin[x][y]=origin[y][x]=true;
        }
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    if (origin[i][k] && origin[k][j])
                        a[i][j]=true;
        memset(vis,0,sizeof(vis));
        dfs(1,n);
        static int id=0;
        printf("Case %d: %d\n",++id,count(vis+1,vis+n+1,true));
    }
    return(0);
}

