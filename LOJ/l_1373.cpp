#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[60][60];
int n,m,u,v,b[60];
bool vis[60];
bool hungary(int x)
{
    if (x==0)
        return(true);
    for (int y=1;y<=m;y++)
    {
        if (vis[y] || y==v || a[u][y]=='0' || a[x][y]=='1')
            continue;
        vis[y]=true;
        if (hungary(b[y]))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int solve()
{
    memset(b,0,sizeof(b));
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=i!=u && a[i][v]=='1';
    for (int i=1;i<=m;i++)
        ans+=i!=v && a[u][i]=='1';
    for (int i=1;i<=n;i++)
    {
        if (i==u || a[i][v]=='0')
            continue;
        memset(vis,0,sizeof(vis));
        ans-=hungary(i);
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]=='1')
                {
                    u=i,v=j;
                    ans=max(ans,solve()+2);
                }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

