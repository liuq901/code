#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int inf,n,ans,root,pre[70],graph[70][70];
bool vis[70],circle[70];
void dfs(int t)
{
    vis[t]=true;
    for (int i=1;i<=n;i++)
        if (!vis[i] && graph[t][i]!=inf)
            dfs(i);
}
int exist_circle()
{
    pre[root]=root;
    for (int i=1;i<=n;i++)
        if (!circle[i] && i!=root)
        {
            pre[i]=i;
            graph[i][i]=inf;
            for (int j=1;j<=n;j++)
                if (!circle[j] && graph[j][i]<graph[pre[i]][i])
                    pre[i]=j;
        }
    for (int i=1;i<=n;i++)
    {
        if (circle[i])
            continue;
        memset(vis,0,sizeof(vis));
        int j=i;
        while (!vis[j])
        {
            vis[j]=true;
            j=pre[j];
        }
        if (j==root)
            continue;
        return(j);
    }
    return(-1);
}
void update(int t)
{
    ans+=graph[pre[t]][t];
    for (int i=pre[t];i!=t;i=pre[i])
    {
        ans+=graph[pre[i]][i];
        circle[i]=true;
    }
    for (int i=1;i<=n;i++)
        if (!circle[i] && graph[i][t]!=inf)
            graph[i][t]-=graph[pre[t]][t];
    for (int j=pre[t];j!=t;j=pre[j])
        for (int i=1;i<=n;i++)
        {
            if (circle[i])
                continue;
            if (graph[i][j]!=inf)
                graph[i][t]=min(graph[i][t],graph[i][j]-graph[pre[j]][j]);
            graph[t][i]=min(graph[j][i],graph[t][i]);
        }
}
bool check()
{
    memset(vis,0,sizeof(vis));
    dfs(root);
    for (int i=1;i<=n;i++)
        if (!vis[i])
            return(false);
    return(true);
}
int solve()
{
    root=1;
    ans=0;
    if (!check())
        return(-1);
    memset(circle,0,sizeof(circle));
    int j;
    while ((j=exist_circle())!=-1)
        update(j);
    for (int j=1;j<=n;j++)
        if (j!=root && !circle[j])
            ans+=graph[pre[j]][j];
    return(ans);
}
int e[10010][4];
void build(int m,int mid)
{
    memset(graph,63,sizeof(graph));
    inf=graph[0][0];
    for (int i=1;i<=m;i++)
        if (e[i][2]>=mid)
        {
            int x=e[i][0],y=e[i][1];
            graph[x][y]=min(graph[x][y],e[i][3]);
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,C;
        scanf("%d%d%d",&n,&m,&C);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&e[i][0],&e[i][1],&e[i][2],&e[i][3]);
            e[i][0]++,e[i][1]++;
        }
        int l=1,r=1000000,ans=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            build(m,mid);
            int tmp=solve();
            if (tmp==-1 || tmp>C)
                r=mid-1;
            else
                ans=mid,l=mid+1;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("impossible\n");
        else
            printf("%d kbps\n",ans);
    }
    return(0);
}

