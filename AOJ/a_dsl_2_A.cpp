#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,x;
};
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=2147483647;
    if (a[x].l==a[x].r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void modify(int x,int pos,int value)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=value;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    pos<=mid?modify(ls,pos,value):modify(rs,pos,value);
    a[x].x=min(a[ls].x,a[rs].x);
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
        return(min(query(ls,l,mid),query(rs,mid+1,r)));
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
            modify(1,x+1,y);
        else
            printf("%d\n",query(1,x+1,y+1));
    }
    return(0);
}

