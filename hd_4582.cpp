#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[2010],up[2010],dep[2010],b[2010],a[4010][2],f[2010][2010];
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        fa[y]=x;
        dep[y]=dep[x]+1;
        dfs(y,x);
    }
}
int dp(int x,int limit)
{
    if (up[x]<=limit)
        return(1<<30);
    if (f[x][limit]!=-1)
        return(f[x][limit]);
    int &ret=f[x][limit];
    ret=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==fa[x])
            continue;
        ret+=min(dp(y,0)+1,dp(y,limit+1));
    }
    return(ret);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        dfs(1,0);
        memset(up,63,sizeof(up));
        for (int i=n;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (dep[x]<dep[y])
                swap(x,y);
            up[x]=min(up[x],dep[x]-dep[y]);
        }
        memset(f,-1,sizeof(f));
        printf("%d\n",dp(1,0));
    }
    return(0);
}

