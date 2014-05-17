#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int v[110],b[1010],a[10010][2],vis[1010][110];
void dfs(int x,int id)
{
    vis[x][id]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!vis[y][id])
            dfs(y,id);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int K,n,m;
        scanf("%d%d%d",&K,&n,&m);
        for (int i=1;i<=K;i++)
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
        }
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=K;i++)
            dfs(v[i],i);
        int ans=0;
        for (int i=1;i<=n;i++)
            ans+=count(vis[i]+1,vis[i]+K+1,true)==K;
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

