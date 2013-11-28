#include <cstdio>
typedef long long ll;
struct tree
{
    int l,r;
    bool inv;
    ll sum;
};
tree a[20][270000];
int v[100010];
void build(tree *a,int x,int l,int r,int pos)
{
    a[x].l=l,a[x].r=r,a[x].inv=false;
    if (l==r)
    {
        a[x].sum=v[l]>>pos&1;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(a,ls,l,mid,pos);
    build(a,rs,mid+1,r,pos);
    a[x].sum=a[ls].sum+a[rs].sum;
}
void update(tree *a,int x)
{
    if (!a[x].inv)
        return;
    a[x].inv=false;
    a[x].sum=a[x].r-a[x].l+1-a[x].sum;
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].inv=!a[ls].inv;
        a[rs].inv=!a[rs].inv;
    }
}
ll query(tree *a,int x,int l,int r)
{
    update(a,x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].sum);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(a,ls,l,r));
    else if (l>mid)
        return(query(a,rs,l,r));
    else
        return(query(a,ls,l,mid)+query(a,rs,mid+1,r));
}
void modify(tree *a,int x,int l,int r)
{
    update(a,x);
    if (a[x].l==l && a[x].r==r)
    {
        a[x].inv=!a[x].inv;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(a,ls,l,r);
    else if (l>mid)
        modify(a,rs,l,r);
    else
    {
        modify(a,ls,l,mid);
        modify(a,rs,mid+1,r);
    }
    update(a,ls);
    update(a,rs);
    a[x].sum=a[ls].sum+a[rs].sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for (int i=0;i<20;i++)
        build(a[i],1,1,n,i);
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if (op==1)
        {
            ll ans=0;
            for (int i=0;i<20;i++)
                ans+=query(a[i],1,l,r)<<i;
            printf("%I64d\n",ans);
        }
        else
        {
            int x;
            scanf("%d",&x);
            for (int i=0;i<20;i++)
            {
                int p=x>>i&1;
                if (p==0)
                    continue;
                modify(a[i],1,l,r);
            }
        }
    }
    return(0);
}

