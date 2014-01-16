#include <cstdio>
#include <algorithm>
using namespace std;
int dep[100010],b[100010],a[100010][2],fa[100010][18];
void dfs(int x)
{
    for (int i=1;i<18;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        dep[y]=dep[x]+1;
        fa[y][0]=x;
        dfs(y);
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    for (int i=17;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y)
        return(x);
    for (int i=17;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
int main()
{
    int n;
    scanf("%d",&n);
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        int K;
        scanf("%d",&K);
        for (int j=1;j<=K;j++)
        {
            int x;
            scanf("%d",&x);
            a[++tot][0]=x+1,a[tot][1]=b[i],b[i]=tot;
        }
    }
    dep[1]=1;
    dfs(1);
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        printf("%d\n",lca(x,y)-1);
    }
    return(0);
}

