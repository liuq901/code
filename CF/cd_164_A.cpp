#include <cstdio>
#include <cstring>
const int N=100010;
int v[N],b[N],e[N][2],a[N][2];
bool f[N],g[N];
void dfs1(int x)
{
    f[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (v[y]!=1 && !f[y])
            dfs1(y);
    }
}
void dfs2(int x)
{
    g[x]=true;
    if (v[x]==1)
        return;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!g[y])
            dfs2(y);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[i][0]=x,e[i][1]=y;
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
    }
    for (int i=1;i<=n;i++)
        if (v[i]==1 && !f[i])
            dfs1(i);
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
    {
        int x=e[i][0],y=e[i][1];
        a[i][0]=x,a[i][1]=b[y],b[y]=i;
    }
    for (int i=1;i<=n;i++)
        if (v[i]==2 && !g[i])
            dfs2(i);
    for (int i=1;i<=n;i++)
        printf("%d\n",f[i] && g[i]);
    return(0);
}

