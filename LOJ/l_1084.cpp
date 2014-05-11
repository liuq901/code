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
    a[x].l=l,a[x].r=r,a[x].x=1<<30;
    if (l==r)
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
int l[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        for (int i=1;i<=n;i++)
            scanf("%d",&l[i]);
        sort(l+1,l+n+1);
        build(1,0,n);
        modify(1,0,0);
        for (int i=1;i<=n;i++)
        {
            int p=lower_bound(l+1,l+n+1,l[i]-2*K)-l-1;
            if (p<=i-3)
            {
                int x=query(1,p,i-3);
                if (x!=1<<30)
                    modify(1,i,x+1);
            }
        }
        static int id=0;
        printf("Case %d: ",++id);
        int ans=query(1,n,n);
        if (ans==1<<30)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

