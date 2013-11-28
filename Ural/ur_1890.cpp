#include <cstdio>
typedef long long ll;
struct tree
{
    int l,r;
    ll x,k;
};
tree a[200010];
int n,dep,sum[50010],v[50010],l[50010],r[50010],last[50010],left[50010],right[50010];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updata(int x)
{
    a[x].x+=a[x].k*(a[x].r-a[x].l+1);
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].k+=a[x].k;
        a[rs].k+=a[x].k;
    }
    a[x].k=0;
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls);
    updata(rs);
    a[x].x=a[ls].x+a[rs].x;
}
void add(int x,int l,int r,ll value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].k+=value;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        add(ls,l,r,value);
    else if (l>mid)
        add(rs,l,r,value);
    else
    {
        add(ls,l,mid,value);
        add(rs,mid+1,r,value);
    }
    update(x);
}
ll find(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(find(ls,l,r));
    else if (l>mid)
        return(find(rs,l,r));
    else
        return(find(ls,l,mid)+find(rs,mid+1,r));
}
void dfs(int x)
{
    left[x]=++dep;
    sum[x]=1;
    for (int i=l[x];i;i=r[i])
    {
        dfs(i);
        sum[x]+=sum[i];
    }
    right[x]=dep;
}
int main()
{
    int Q;
    scanf("%d%d%d",&n,&Q,&v[1]);
    for (int i=2;i<=n;i++)
    {
        int fa;
        scanf("%d%d",&fa,&v[i]);
        fa++;
        if (!l[fa])
            l[fa]=i;
        else
            r[last[fa]]=i;
        last[fa]=i;
    }
    dfs(1);
    build(1,1,n);
    for (int i=1;i<=n;i++)
        add(1,left[i],left[i],v[i]);
    while (Q--)
    {
        char op[100];
        int x,y,z;
        scanf("%s%d%d%d",op,&x,&y,&z);
        x++;
        if (op[0]=='e')
        {
            ll p=find(1,left[x],left[x]);
            if (p<y)
                add(1,left[x],left[x],z);
        }
        else
        {
            ll p=find(1,left[x],right[x]);
            if (p<ll(y)*sum[x])
                add(1,left[x],right[x],z);
        }
    }
    for (int i=1;i<=n;i++)
    {
        ll p=find(1,left[i],left[i]);
        printf("%lld\n",p);
    }
    return(0);
}

