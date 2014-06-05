#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int idx,color[10010],b[10010],c[10010],cnt[10010],dfn[10010],low[10010],a[40010][2];
bool vis[10010];
stack <int> s;
void tarjan(int x,int father)
{
    dfn[x]=low[x]=++idx;
    s.push(x);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (!dfn[y])
        {
            tarjan(y,x);
            low[x]=min(low[x],low[y]);
        }
        else
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        cnt[++c[0]]=0;
        while (1)
        {
            int y=s.top();
            s.pop();
            c[y]=c[0];
            cnt[c[0]]++;
            if (x==y)
                break;
        }
    }
}
bool dfs(int x,int kind)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (c[y]!=kind)
            continue;
        if (color[y]==-1)
        {
            color[y]=color[x]^1;
            if (dfs(y,kind))
                return(true);
        }
        else if (color[y]==color[x])
            return(true);
    }
    return(false);
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
            x++,y++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(dfn,0,sizeof(dfn));
        c[0]=idx=0;
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i,0);
        memset(vis,0,sizeof(vis));
        memset(color,-1,sizeof(color));
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (vis[c[i]])
                continue;
            vis[c[i]]=true;
            color[i]=0;
            if (dfs(i,c[i]))
                ans+=cnt[c[i]];
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

