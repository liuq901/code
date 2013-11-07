#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r;
    pair <bool,ll> x;
};
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=make_pair(false,0);
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
pair <bool,ll> query(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
        return(a[x].x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
        return(max(query(ls,l,mid),query(rs,mid+1,r)));
}
void insert(int x,int pos,pair <bool,ll> value)
{
    if (a[x].l==a[x].r)
    {
        a[x].x=value;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (pos<=mid)
        insert(ls,pos,value);
    else
        insert(rs,pos,value);
    a[x].x=max(a[ls].x,a[rs].x);
}
bool ok[100010];
ll f[100010];
int c[100010],h[100010];
inline bool cmp(int x,int y)
{
    return(h[x]<h[y] || h[x]==h[y] && x>y);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,L;
        scanf("%d%d",&n,&L);
        for (int i=1;i<=n;i++)
        {
            c[i]=i;
            scanf("%d",&h[i]);
        }
        sort(c+1,c+n+1,cmp);
        memset(f,-63,sizeof(f));
        memset(ok,0,sizeof(ok));
        build(1,1,n);
        for (int i=1;i<=n;i++)
        {
            int x=c[i];
            if (x<=L)
            {
                ok[x]=true;
                f[x]=ll(h[x])*h[x];
            }
            if (x>1)
            {
                pair <bool,ll> best=query(1,max(1,x-L),x-1);
                if (best.first)
                {
                    ok[x]=true;
                    f[x]=max(f[x],best.second+ll(h[x])*h[x]);
                }
            }
            if (ok[x])
                insert(1,x,make_pair(true,f[x]-h[x]));
        }
        static int id=0;
        printf("Case #%d: ",++id);
        if (!ok[n])
            printf("No solution\n");
        else
            printf("%I64d\n",f[n]);
    }
    return(0);
}

