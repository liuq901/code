#include <cstdio>
#include <cstring>
int n,idx,dep[30010],in[30010],out[30010],v[30010],b[30010],c[30010],a[60010][2],fa[30010][15];
void modify(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=value;
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int lca(int x,int y)
{
    if (dep[x]<dep[y])
        return(lca(y,x));
    for (int i=14;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y)
        return(x);
    for (int i=14;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
void dfs(int x)
{
    in[x]=++idx;
    for (int i=1;i<=14;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==fa[x][0])
            continue;
        fa[y][0]=x;
        dep[y]=dep[x]+1;
        dfs(y);
    }
    out[x]=idx;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++,y++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        idx=0;
        dep[1]=1;
        dfs(1);
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            modify(in[i],v[i]);
            modify(out[i]+1,-v[i]);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            if (op==0)
            {
                x++,y++;
                int t=lca(x,y);
                printf("%d\n",query(in[x])+query(in[y])-2*query(in[t])+v[t]);
            }
            else
            {
                x++;
                int delta=y-v[x];
                modify(in[x],delta);
                modify(out[x]+1,-delta);
                v[x]=y;
            }
        }
    }
    return(0);
}

