#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r;
    ll x;
};
tree a[140000];
int v[50010],b[50010];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    a[x].x=1LL<<60;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void modify(int x,int l,int r,ll value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].x=min(a[x].x,value);
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
}
ll query(int x,int pos)
{
    if (a[x].l==a[x].r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    return(min(a[x].x,pos<=mid?query(ls,pos):query(rs,pos)));
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        build(1,0,n);
        modify(1,0,0,0);
        for (int i=1;i<=n;i++)
        {
            ll value=query(1,i-1)+v[i];
            int t=min(n,i+b[i]-1);
            modify(1,i,t,value);
        }
        printf("%lld\n",query(1,n));
    }
    return(0);
}

