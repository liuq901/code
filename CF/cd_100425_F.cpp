#include <cstdio>
#include <queue>
using namespace std;
int len[100010],dep[100010],c[100010],to[100010],b[100010],a[1000000][2],fa[100010][17];
void cycle(int x,int y)
{
    static int id=0;
    id++;
    int u=x,v=y;
    while (x!=y)
    {
        if (dep[x]>dep[y])
        {
            to[x]=u;
            c[x]=id;
            x=fa[x][0];
        }
        else
        {
            to[y]=v;
            c[y]=id;
            y=fa[y][0];
        }
        len[id]++;
    }
    c[x]=id;
    len[id]++;
}
void init()
{
    queue <int> Q;
    Q.push(1);
    dep[1]=1;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for (int i=1;i<=16;i++)
            fa[x][i]=fa[fa[x][i-1]][i-1];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (y==fa[x][0])
                continue;
            if (dep[y]!=0 && c[x]==0)
                cycle(x,y);
            else if (dep[y]==0)
            {
                dep[y]=dep[x]+1;
                fa[y][0]=x;
                Q.push(y);
            }
        }
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y])
        swap(x,y);
    for (int i=16;i>=0;i--)
        if (dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y)
        return(x);
    for (int i=16;i>=0;i--)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return(fa[x][0]);
}
int go(int x,int t)
{
    if (c[t]==0)
        return(t);
    if (c[x]==c[t])
        return(x);
    for (int i=16;i>=0;i--)
        if (dep[fa[x][i]]>=dep[t] && c[fa[x][i]]!=c[t])
            x=fa[x][i];
    return(fa[x][0]);
}
int up(int x,int len)
{
    for (int i=16;i>=0;i--)
        if (len>>i&1)
            x=fa[x][i];
    return(x);
}
int calc(int x,int y)
{
    int t=lca(x,y);
    int u=go(x,t);
    int v=go(y,t);
    int l1=dep[x]-dep[u];
    int l2=dep[y]-dep[v];
    int len1=dep[u]+dep[v]-2*dep[t];
    int len2=c[t]==0?1<<30:len[c[t]]-len1;
    if (len1<=len2)
    {
        int mid=(l1+l2+len1)/2;
        if (mid<=l1+dep[u]-dep[t])
            return(up(x,mid));
        else
        {
            mid-=l1+dep[u]-dep[t];
            return(up(y,l2+dep[v]-dep[t]-mid));
        }
    }
    else
    {
        int mid=(l1+l2+len2)/2;
        if (mid<=l1)
            return(up(x,mid));
        else
        {
            mid-=l1;
            int p=to[u];
            if (mid<=dep[p]-dep[u])
                return(up(p,dep[p]-dep[u]-mid));
            else
            {
                mid-=dep[p]-dep[u]+1;
                int q=to[v];
                if (mid<=dep[q]-dep[v])
                    return(up(q,mid));
                else
                {
                    mid-=dep[q]-dep[v];
                    return(up(y,l2-mid));
                }
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
    }
    init();
    int Q,now=1;
    scanf("%d",&Q);
    while (Q--)
    {
        int x;
        scanf("%d",&x);
        x++;
        printf("%d",calc(now,x)-1);
        now=x;
        if (Q)
            printf(" ");
    }
    printf("\n");
    return(0);
}

