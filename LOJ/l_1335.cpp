#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tot,pos[510],a[510][2];
bool vis[510];
void dfs(int x)
{
    pos[x]=++tot;
    vis[x]=true;
    for (int i=0;i<2;i++)
    {
        int y=a[x][i];
        if (!vis[y])
            dfs(y);
    }
}
int p[510];
int calc(int n)
{
    int ans=0;
    p[0]=-1<<30;
    for (int i=1;i<=n;i++)
    {
        int x=pos[i];
        if (x>p[ans])
            p[++ans]=x;
        else
        {
            int t=lower_bound(p,p+ans+1,x)-p;
            p[t]=x;
        }
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i][0],&a[i][1]);
        int ans=1<<30;
        for (int i=1;i<=n;i++)
        {
            tot=0;
            memset(vis,0,sizeof(vis));
            dfs(i);
            ans=min(ans,n-calc(n));
            swap(a[i][0],a[i][1]);
            tot=0;
            memset(vis,0,sizeof(vis));
            dfs(i);
            ans=min(ans,n-calc(n));
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

