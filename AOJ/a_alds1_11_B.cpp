#include <cstdio>
bool vis[110],f[110][110];
int n,tot,in[110],out[110];
void dfs(int x)
{
    in[x]=++tot;
    vis[x]=true;
    for (int i=1;i<=n;i++)
    {
        if (!f[x][i] || vis[i])
            continue;
        dfs(i);
    }
    out[x]=++tot;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int id,K;
        scanf("%d%d",&id,&K);
        for (int j=1;j<=K;j++)
        {
            int x;
            scanf("%d",&x);
            f[id][x]=true;
        }
    }
    for (int i=1;i<=n;i++)
        if (!vis[i])
            dfs(i);
    for (int i=1;i<=n;i++)
        printf("%d %d %d\n",i,in[i],out[i]);
    return(0);
}

