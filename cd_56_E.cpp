#include <cstdio>
#include <algorithm>
using namespace std;
struct domino
{
    int id,h,x;
};
struct tree
{
    int x,l,r;
};
inline bool operator <(const domino &a,const domino &b)
{
    return(a.x<b.x);
}
domino v[100010];
int n,b[100010],ans[100010];
void work()
{
    for (int i=1;i<=n;i++)
    {
        domino tmp;
        tmp.x=v[i].x+v[i].h-1;
        b[i]=upper_bound(v+1,v+n+1,tmp)-v-1;
    }
}
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r;
    if (l==r)
    {
        a[x].x=b[l];
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    a[x].x=max(a[ls].x,a[rs].x);
}
int get(int x,int l,int r)
{
    if (l==a[x].l && r==a[x].r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    else
        return(max(get(ls,l,mid),get(rs,mid+1,r)));
}
void modify(int x,int pos,int value)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=value;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        modify(ls,pos,value);
    else
        modify(rs,pos,value);
    a[x].x=max(a[ls].x,a[rs].x);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,h;
        scanf("%d%d",&x,&h);
        v[i].x=x,v[i].h=h,v[i].id=i;
    }
    sort(v+1,v+n+1);
    work();
    build(1,1,n);
    for (int i=n;i;i--)
    {
        int t=get(1,i,b[i]);
        ans[v[i].id]=t-i+1;
        modify(1,i,t);
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",ans[i],i==n?'\n':' ');
    return(0);
}

