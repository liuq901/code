#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,maxl,maxr,maxs,minl,minr,mins,sum;
    bool change;
};
tree a[270000];
int b[100010];
void updata(int x)
{
    if (!a[x].change)
        return;
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].change=!a[ls].change;
        a[rs].change=!a[rs].change;
    }
    a[x].change=false;
    swap(a[x].maxl,a[x].minl);
    a[x].maxl*=-1,a[x].minl*=-1;
    swap(a[x].maxr,a[x].minr);
    a[x].maxr*=-1,a[x].minr*=-1;
    swap(a[x].maxs,a[x].mins);
    a[x].maxs*=-1,a[x].mins*=-1;
    a[x].sum*=-1;
}
tree merge(tree ls,tree rs)
{
    tree ret;
    ret.sum=ls.sum+rs.sum;
    ret.maxl=max(ls.maxl,ls.sum+rs.maxl);
    ret.minl=min(ls.minl,ls.sum+rs.minl);
    ret.maxr=max(rs.maxr,rs.sum+ls.maxr);
    ret.minr=min(rs.minr,rs.sum+ls.minr);
    ret.maxs=max(max(ls.maxs,rs.maxs),ls.maxr+rs.maxl);
    ret.mins=min(min(ls.mins,rs.mins),ls.minr+rs.minl);
    return(ret);
}
void update(int x)
{
    int ls=x<<1,rs=ls+1,l=a[x].l,r=a[x].r;
    updata(ls),updata(rs);
    a[x]=merge(a[ls],a[rs]);
    a[x].l=l,a[x].r=r,a[x].change=false;
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    a[x].change=false;
    if (l==r)
    {
        a[x].maxl=a[x].maxr=a[x].maxs=a[x].minl=a[x].minr=a[x].mins=a[x].sum=b[l];
        return;
    }
    int ls=x<<1,rs=ls+1,mid=l+r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(x);
}
void modify(int x,int l,int r)
{
    if (l==a[x].l && r==a[x].r)
    {
        a[x].change=!a[x].change;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r);
    else if (l>mid)
        modify(rs,l,r);
    else
    {
        modify(ls,l,mid);
        modify(rs,mid+1,r);
    }
    update(x);
}
tree get(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x]);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    else
        return(merge(get(ls,l,mid),get(rs,mid+1,r)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        build(1,1,n);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int op,x,y;
            scanf("%d%d%d",&op,&x,&y);
            x++,y++;
            if (!op)
                modify(1,x,y);
            else
                printf("%d\n",get(1,x,y).maxs);
        }
    }
    return(0);
}

