#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r,x;
    ll s,a[7];
};
tree a[270000];
ll v[7][100010];
inline ll Sqrt(ll x)
{
    ll ret=ll(sqrt(double(x)));
    while (x/ret>=ret)
        ret++;
    return(ret-1);
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].x=0;
    if (a[x].l==a[x].r)
    {
        for (int i=0;i<=6;i++)
            a[x].a[i]=v[i][a[x].l];
        a[x].s=v[0][a[x].l]>0;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    for (int i=0;i<=6;i++)
        a[x].a[i]=a[ls].a[i]+a[rs].a[i];
    a[x].s=a[ls].s+a[rs].s;
}
inline void updata(int x)
{
    for (int i=0;i<=6;i++)
        a[x].a[i]=i+a[x].x<=6?a[x].a[i+a[x].x]:a[x].s;
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].x+=a[x].x;
        a[rs].x+=a[x].x;
    }
    a[x].x=0;
}
void modify(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].x++;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r);
    else if (l>mid)
        modify(rs,l,r);
    else
    {
        modify(ls,l,mid);
        modify(rs,mid+1,r);
    }
    for (int i=0;i<=6;i++)
    {
        ll u=i+a[ls].x<=6?a[ls].a[i+a[ls].x]:a[ls].s;
        ll v=i+a[rs].x<=6?a[rs].a[i+a[rs].x]:a[rs].s;
        a[x].a[i]=u+v;
    }
}
ll get(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].a[0]);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(get(ls,l,r));
    else if (l>mid)
        return(get(rs,l,r));
    else
        return(get(ls,l,mid)+get(rs,mid+1,r));
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%I64d",&v[0][i]);
        for (int i=1;i<=6;i++)
            for (int j=1;j<=n;j++)
                v[i][j]=Sqrt(v[i-1][j]);
        build(1,1,n);
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case #%d:\n",++id);
        while (Q--)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if (l>r)
                swap(l,r);
            if (op==0)
                modify(1,l,r);
            else
                printf("%I64d\n",get(1,l,r));
        }
        printf("\n");
    }
    return(0);
}

