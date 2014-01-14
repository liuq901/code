#include <cstdio>
struct tree
{
    int l,r,x;
};
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=0;
    if (a[x].l==a[x].r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void modify(int x,int pos,int value)
{
    a[x].x+=value;
    if (a[x].l==a[x].r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    pos<=mid?modify(ls,pos,value):modify(rs,pos,value);
}
int query(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
        return(query(ls,l,mid)+query(rs,mid+1,r));
}
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    build(1,1,n);
    while (Q--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if (op==0)
            modify(1,x,y);
        else
            printf("%d\n",query(1,x,y));
    }
    return(0);
}

