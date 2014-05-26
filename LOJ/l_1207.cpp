#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,x;
};
tree a[524300];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void modify(int x,int l,int r,int value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].x=value;
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
int get(int x,int pos)
{
    if (a[x].l==a[x].r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    return(max(a[x].x,pos<=mid?get(ls,pos):get(rs,pos)));
}
bool vis[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        build(1,1,2*n);
        for (int i=1;i<=n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            modify(1,l,r,i);
        }
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=2*n;i++)
            vis[get(1,i)]=true;
        static int id=0;
        printf("Case %d: %d\n",++id,count(vis+1,vis+n+1,true));
    }
    return(0);
}

