#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r;
    ll k,x;
};
tree a[800010];
int v[200010];
char buf[100000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].k=0;
    if (l==r)
    {
        a[x].x=v[l];
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[x].x=min(a[ls].x,a[rs].x);
}
void updata(int x)
{
    int ls=x<<1,rs=ls+1;
    a[ls].k+=a[x].k;
    a[rs].k+=a[x].k;
    a[x].x+=a[x].k;
    a[x].k=0;
}
void modify(int x,int l,int r,int v)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].k+=v;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,v);
    else if (l>mid)
        modify(rs,l,r,v);
    else
    {
        modify(ls,l,mid,v);
        modify(rs,mid+1,r,v);
    }
    a[x].x=min(a[ls].x+a[ls].k,a[rs].x+a[rs].k);
}
ll get(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x].x+a[x].k);
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    return(min(get(ls,l,mid),get(rs,mid+1,r)));
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    build(1,1,n);
    int Q;
    scanf("%d",&Q);
    gets(buf);
    while (Q--)
    {
        gets(buf);
        int l,r,v;
        if (sscanf(buf,"%d%d%d",&l,&r,&v)==3)
            if (l<=r)
                modify(1,l+1,r+1,v);
            else
            {
                modify(1,1,r+1,v);
                modify(1,l+1,n,v);
            }
        else if (l<=r)
            printf("%I64d\n",get(1,l+1,r+1));
        else
            printf("%I64d\n",min(get(1,1,r+1),get(1,l+1,n)));
    }
    return(0);
}

