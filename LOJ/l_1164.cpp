#include <cstdio>
typedef long long ll;
struct tree
{
    int l,r;
    ll sum,delta;
};
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].sum=a[x].delta=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updata(int x)
{
    a[x].sum+=a[x].delta*(a[x].r-a[x].l+1);
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].delta+=a[x].delta;
        a[rs].delta+=a[x].delta;
    }
    a[x].delta=0;
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls);
    updata(rs);
    a[x].sum=a[ls].sum+a[rs].sum;
}
void modify(int x,int l,int r,int value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].delta+=value;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,value);
    else if (l>mid)
        modify(rs,l,r,value);
    else
    {
        modify(ls,l,mid,value);
        modify(rs,mid+1,r,value);
    }
    update(x);
}
ll query(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].sum);
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        build(1,0,n-1);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if (op==0)
            {
                int x;
                scanf("%d",&x);
                modify(1,l,r,x);
            }
            else
                printf("%lld\n",query(1,l,r));
        }
    }
    return(0);
}

