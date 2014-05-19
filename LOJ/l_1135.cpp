#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,cnt,ans[3];
};
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].cnt=a[x].ans[1]=a[x].ans[2]=0,a[x].ans[0]=r-l+1;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updata(int x)
{
    int p=a[x].cnt%3;
    rotate(a[x].ans,a[x].ans+p,a[x].ans+3);
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].cnt+=a[x].cnt;
        a[rs].cnt+=a[x].cnt;
    }
    a[x].cnt=0;
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls);
    updata(rs);
    for (int i=0;i<3;i++)
        a[x].ans[i]=a[ls].ans[i]+a[rs].ans[i];
}
void add(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].cnt++;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        add(ls,l,r);
    else if (l>mid)
        add(rs,l,r);
    else
    {
        add(ls,l,mid);
        add(rs,mid+1,r);
    }
    update(x);
}
int query(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].ans[0]);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    return(query(ls,l,mid)+query(rs,mid+1,r));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        build(1,1,n);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            l++,r++;
            if (op==0)
                add(1,l,r);
            else
                printf("%d\n",query(1,l,r));
        }
    }
    return(0);
}

