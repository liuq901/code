#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,len;
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.len<b.len);
}
edge e[100010];
int tot,f[50010],b[50010],a[100010][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=z,a[tot][2]=b[y],b[y]=tot;
}
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
void kruskal(int n,int m)
{
    for (int i=1;i<=n;i++)
    {
        f[i]=i;
        b[i]=0;
    }
    sort(e+1,e+m+1);
    tot=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(e[i].x),y=find(e[i].y);
        if (x==y)
            continue;
        add(x,y,e[i].len);
        f[x]=y;
    }
}
int dep[50010],fa[50010][16],len[50010][16];
void dfs(int x)
{
    for (int i=1;i<=15;i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
        len[x][i]=max(len[x][i-1],len[fa[x][i-1]][i-1]);
    }
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==fa[x][0])
            continue;
        dep[y]=dep[x]+1;
        fa[y][0]=x;
        len[y][0]=a[i][1];
        dfs(y);
    }
}
int calc(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    int ret=0;
    for (int i=15;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
        {
            ret=max(ret,len[x][i]);
            x=fa[x][i];
        }
    if (x!=y)
    {
        for (int i=15;i>=0;i--)
            if (fa[x][i]!=fa[y][i])
            {
                ret=max(ret,max(len[x][i],len[y][i]));
                x=fa[x][i],y=fa[y][i];
            }
        ret=max(ret,max(len[x][0],len[y][0]));
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].len);
        kruskal(n,m);
        dep[1]=1;
        dfs(1);
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int n,m;
            scanf("%d%d",&n,&m);
            printf("%d\n",calc(n,m));
        }
    }
    return(0);
}

