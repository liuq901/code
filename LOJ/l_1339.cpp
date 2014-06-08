#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,lid,rid,lcnt,rcnt,cnt;
};
tree a[270000];
int v[100010];
tree update(const tree &ls,const tree &rs)
{
    tree ret;
    ret.l=ls.l;
    ret.r=rs.r;
    ret.lid=ls.lid;
    ret.rid=rs.rid;
    ret.lcnt=ls.lid==ls.rid && ls.rid==rs.lid?ls.cnt+rs.lcnt:ls.lcnt;
    ret.rcnt=rs.lid==rs.rid && rs.lid==ls.rid?rs.cnt+ls.rcnt:rs.rcnt;
    ret.cnt=max(max(ls.cnt,rs.cnt),ls.rid==rs.lid?ls.rcnt+rs.lcnt:0);
    return(ret);
}
void build(int x,int l,int r)
{
    if (l==r)
    {
        a[x].l=a[x].r=l;
        a[x].lcnt=a[x].rcnt=a[x].cnt=1;
        a[x].lid=a[x].rid=v[l];
        return;
    }
    int ls=x<<1,rs=ls+1,mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[x]=update(a[ls],a[rs]);
}
tree query(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x]);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
        return(update(query(ls,l,mid),query(rs,mid+1,r)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%*d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        build(1,1,n);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,l,r).cnt);
        }
    }
    return(0);
}

