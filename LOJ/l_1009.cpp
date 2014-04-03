#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[20010],use[20010];
int p[2],b[20010],a[200010][2];
void dfs(int x,int id)
{
    p[id]++;
    vis[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!vis[y])
            dfs(y,id^1);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n=0,m;
        scanf("%d",&m);
        memset(b,0,sizeof(b));
        memset(use,0,sizeof(use));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
            n=max(n,max(x,y));
            use[x]=use[y]=true;
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        for (int i=1;i<=n;i++)
            if (use[i] && !vis[i])
            {
                p[0]=p[1]=0;
                dfs(i,1);
                ans+=max(p[0],p[1]);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

