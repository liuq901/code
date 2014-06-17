#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int N,idx,c[1010],dfn[1010],low[1001],b[1010],a[1000010][2];
bool in[1010];
stack <int> s;
void tarjan(int x)
{
    dfn[x]=low[x]=++idx;
    in[x]=true;
    s.push(x);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (in[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        N++;
        while (1)
        {
            int y=s.top();
            s.pop();
            in[y]=false,c[y]=N;
            if (x==y)
                break;
        }
    }
}
bool vis[1010],adj[1010][1010];
void dfs(int x,int id)
{
    vis[x]=true;
    if (c[x]!=id)
        adj[id][c[x]]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!vis[y])
            dfs(y,id);
    }
}
int wh[1010],from[1010],q[1010],dx[1010],dy[1010];
bool bfs()
{
    bool ret=false;
    int l=1,r=0;
    for (int i=1;i<=N;i++)
        if (!wh[i])
            q[++r]=i;
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy));
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (dy[y]==0)
            {
                dy[y]=dx[x]+1;
                if (!from[y])
                    ret=true;
                else
                {
                    dx[from[y]]=dx[x]+2;
                    q[++r]=from[y];
                }
            }
        }
    }
    return(ret);
}
bool dfs(int x)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (dy[y]==dx[x]+1)
        {
            dy[y]=0;
            if (!from[y] || dfs(from[y]))
            {
                wh[x]=y;
                from[y]=x;
                return(true);
            }
        }
    }
    return(false);
}
int hopcroft()
{
    memset(from,0,sizeof(from));
    memset(wh,0,sizeof(wh));
    int ans=0;
    while (bfs())
        for (int i=1;i<=N;i++)
            if (!wh[i] && dfs(i))
                ans++;
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
        }
        memset(dfn,0,sizeof(dfn));
        idx=N=0;
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        memset(adj,0,sizeof(adj));
        for (int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i,c[i]);
        }
        memset(b,0,sizeof(b));
        int tot=0;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if (adj[i][j])
                    a[++tot][0]=j,a[tot][1]=b[i],b[i]=tot;
        static int id=0;
        printf("Case %d: %d\n",++id,N-hopcroft());
    }
    return(0);
}

