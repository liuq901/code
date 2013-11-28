#include <cstdio>
typedef long long ll;
struct tree
{
    int l,r,len;
    ll left,right,cost,sum,delta;
};
tree a[270000];
ll s[100010];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].len=r-l+1,a[x].delta=0;
    a[x].left=a[x].right=a[x].sum=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void change(int x,ll delta)
{
    a[x].delta+=delta;
    a[x].sum+=delta*a[x].len;
    a[x].left+=delta*a[x].len*(a[x].len+1)/2;
    a[x].right+=delta*a[x].len*(a[x].len+1)/2;
    a[x].cost+=delta*s[a[x].len];
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    change(ls,a[x].delta);
    change(rs,a[x].delta);
    a[x].delta=0;
}
tree merge(const tree &a,const tree &b)
{
    tree ret;
    ret.sum=a.sum+b.sum;
    ret.len=a.len+b.len;
    ret.left=a.left+b.left+a.sum*b.len;
    ret.right=a.right+b.right+b.sum*a.len;
    ret.cost=a.cost+b.cost+a.len*b.left+b.len*a.right;
    ret.delta=0;
    ret.l=a.l;
    ret.r=b.r;
    return(ret);
}
void modify(int x,int l,int r,int k)
{
    if (l==a[x].l && r==a[x].r)
    {
        change(x,k);
        return;
    }
    update(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,k);
    else if (l>mid)
        modify(rs,l,r,k);
    else
    {
        modify(ls,l,mid,k);
        modify(rs,mid+1,r,k);
    }
    a[x]=merge(a[ls],a[rs]);
}
tree get(int x,int l,int r)
{
    if (l==a[x].l && r==a[x].r)
        return(a[x]);
    update(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    return(merge(get(ls,l,mid),get(rs,mid+1,r)));
}
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    for (int i=1;i<=n;i++)
        s[i]=s[i-1]+ll(i)*(i+1)/2;
    build(1,1,n-1);
    while (Q--)
    {
        char op[20];
        int l,r;
        scanf("%s%d%d",op,&l,&r);
        if (op[0]=='c')
        {
            int x;
            scanf("%d",&x);
            modify(1,l,r-1,x);
        }
        else
            printf("%.10f\n",double(get(1,l,r-1).cost)/(ll(r-l)*(r-l+1)/2));
    }
    return(0);
}

