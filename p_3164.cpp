#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=110,INF=99999999;
int n,m,root,pre[N],X[N],Y[N];
double ans,graph[N][N];
bool vis[N],circle[N];
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(int a,int b)
{
    return(sqrt(sqr(X[a]-X[b])+sqr(Y[a]-Y[b])));
}
void dfs(int t)
{
    vis[t]=true;
    for (int i=1;i<=n;i++)
        if (!vis[i] && graph[t][i]!=INF)
            dfs(i);
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
int exist_circle()
{
    root=1;
    pre[root]=root;
    for (int i=1;i<=n;i++)
        if (!circle[i] && i!=root)
        {
            pre[i]=i;
            graph[i][i]=INF;
            for (int j=1;j<=n;j++)
                if (!circle[j] && graph[j][i]<graph[pre[i]][i])
                    pre[i]=j;
        }
    for (int i=1;i<=n;i++)
    {
        if (circle[i])
            continue;
        memset(vis,0,sizeof(vis));
        int j;
        for (j=i;!vis[j];j=pre[j])
            vis[j]=true;
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
        ans+=graph[pre[i]][i],circle[i]=true;
    for (int i=1;i<=n;i++)
        if (!circle[i] && graph[i][t]!=INF)
            graph[i][t]-=graph[pre[t]][t];
    for (int j=pre[t];j!=t;j=pre[j])
        for (int i=1;i<=n;i++)
        {
            if (circle[i])
                continue;
            if (graph[i][j]!=INF)
                graph[i][t]=min(graph[i][t],graph[i][j]-graph[pre[j]][j]);
            graph[t][i]=min(graph[j][i],graph[t][i]);
        }
}
void solve()
{
    memset(circle,0,sizeof(circle));
    int j;
    while ((j=exist_circle())!=-1)
        update(j);
    for (j=1;j<=n;j++)
        if (j!=root && !circle[j])
            ans+=graph[pre[j]][j];
    printf("%.2f\n",ans);
}
int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                graph[i][j]=INF;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            graph[x][y]=dist(x,y);
        }
        root=1,ans=0;
        if (!check())
            printf("poor snoopy\n");
        else
            solve();
    }
    return(0);
}

