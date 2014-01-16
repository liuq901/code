#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
bool circle[110],visit[110];
int n,ans,root,pre[110],graph[110][110];
int exist_circle()
{
    pre[root]=root;
    for (int i=1;i<=n;i++)
    {
        if (!circle[i] && i!=root)
        {
            pre[i]=i;
            graph[i][i]=inf;
            for (int j=1;j<=n;j++)
                if (!circle[j] && graph[j][i]<graph[pre[i]][i])
                    pre[i]=j;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (circle[i])
            continue;
        memset(visit,0,sizeof(visit));
        int j=i;
        while (!visit[j])
        {
            visit[j]=true;
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
void solve()
{
    memset(circle,0,sizeof(circle));
    int j;
    while ((j=exist_circle())!=-1)
        update(j);
    for (j=1;j<=n;j++)
        if (j!=root && !circle[j])
            ans+=graph[pre[j]][j];
    printf("%d\n",ans);
}
int main()
{
    int m;
    scanf("%d%d%d",&n,&m,&root);
    root++;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            graph[i][j]=inf;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        scanf("%d",&graph[x][y]);
    }
    solve();
    return(0);
}

