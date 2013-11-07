#include <cstdio>
#include <cstring>
int fa[3010],dep[3010],b[3010],a[6010][2];
bool cycle[3010];
bool dfs(int x,int father)
{
    fa[x]=father;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        if (fa[y]!=-1)
        {
            for (int j=x;j!=y;j=fa[j])
                cycle[j]=true;
            cycle[y]=true;
            return(true);
        }
        fa[y]=x;
        if (dfs(y,x))
            return(true);
    }
    return(false);
}
void dfs2(int x,int father)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (cycle[y] || y==father)
            continue;
        dep[y]=dep[x]+1;
        dfs2(y,x);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
    }
    memset(fa,-1,sizeof(fa));
    dfs(1,0);
    memset(dep,-1,sizeof(dep));
    for (int i=1;i<=n;i++)
        if (cycle[i])
        {
            dep[i]=0;
            dfs2(i,0);
        }
    for (int i=1;i<=n;i++)
        printf("%d%c",dep[i],i==n?'\n':' ');
    return(0);
}

