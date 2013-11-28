#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,v;
};
tree a[131100];
vector <int> son[50010];
int tot,L[50010],R[50010],b[50010],c[50010],f[50010],g[50010],ans[50010];
inline bool cmp(int x,int y)
{
    return(c[x]>c[y]);
}
void dfs(int x)
{
    L[x]=tot+1;
    for (int i=0;i<son[x].size();i++)
        dfs(son[x][i]);
    R[x]=++tot;
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].v=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
inline int best(int x,int y)
{
    return(b[x]>b[y]?x:y);
}
void insert(int x,int pos,int id)
{
    if (a[x].l==a[x].r)
    {
        a[x].v=id;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        insert(ls,pos,id);
    else
        insert(rs,pos,id);
    a[x].v=best(a[ls].v,a[rs].v);
}
int query(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x].v);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
        return(best(query(ls,l,mid),query(rs,mid+1,r)));
}
int main()
{
    int T;
    scanf("%d",&T);
    b[0]=-1;
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            son[i].clear();
        for (int i=2;i<=n;i++)
        {
            int fa;
            scanf("%d%d%d",&fa,&b[i],&c[i]);
            son[fa+1].push_back(i);
        }
        tot=0;
        dfs(1);
        build(1,1,n);
        for (int i=1;i<=n;i++)
            f[i]=i;
        sort(f+1,f+n+1,cmp);
        for (int i=1;i<=n;i++)
            g[i]=f[i];
        int p=1,q=1;
        while (p<=n || q<=n)
        {
            int x=f[p],y=g[q];
            if (p<=n && c[x]==c[y])
            {
                ans[x]=query(1,L[x],R[x]);
                p++;
            }
            else
            {
                insert(1,R[y],y);
                q++;
            }
        }
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",ans[x+1]-1);
        }
    }
    return(0);
}

