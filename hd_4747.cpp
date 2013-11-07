#include <cstdio>
#include <cstring>
typedef long long ll;
const int N=200010;
struct tree
{
    int l,r,ma,all;
    ll sum;
};
tree a[524300];
bool flag[N];
int v[N],f[N],next[N],pos[N];
void updata(int x)
{
    if (a[x].all==-1)
        return;
    a[x].ma=a[x].all;
    a[x].sum=ll(a[x].all)*(a[x].r-a[x].l+1);
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].all=a[rs].all=a[x].all;
    }
    a[x].all=-1;
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls);
    updata(rs);
    a[x].sum=a[ls].sum+a[rs].sum;
    a[x].ma=a[rs].ma;
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].all=-1;
    if (l==r)
    {
        a[x].sum=a[x].ma=f[l];
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(x);
}
void modify(int x,int l,int r,int value)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
    {
        a[x].all=value;
        return;
    }
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
int get(int x,int l,int r,int value)
{
    updata(x);
    if (a[x].l==a[x].r)
        return(a[x].ma>=value?a[x].l:-1);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r,value));
    else if (l>mid)
        return(get(rs,l,r,value));
    else if (a[ls].ma>=value)
        return(get(ls,l,mid,value));
    else
        return(get(rs,mid+1,r,value));
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
    return(query(ls,l,mid)+query(rs,mid+1,r));
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        memset(flag,0,sizeof(flag));
        int now=0;
        for (int i=1;i<=n;i++)
        {
            if (v[i]<=n)
                flag[v[i]]=true;
            while (flag[now])
                now++;
            f[i]=now;
        }
        for (int i=0;i<=n;i++)
            pos[i]=next[i]=n+1;
        for (int i=n;i;i--)
        {
            if (v[i]>n)
                continue;
            next[i]=pos[v[i]];
            pos[v[i]]=i;
        }
        build(1,1,n);
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=query(1,i,n);
            int pos=get(1,i+1,next[i]-1,v[i]);
            if (pos!=-1)
                modify(1,pos,next[i]-1,v[i]);
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

