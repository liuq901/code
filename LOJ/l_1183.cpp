#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,sum,num;
};
tree a[270000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].sum=0,a[x].num=-1;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updata(int x)
{
    if (a[x].num==-1)
        return;
    a[x].sum=a[x].num*(a[x].r-a[x].l+1);
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].num=a[rs].num=a[x].num;
    }
    a[x].num=-1;
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls);
    updata(rs);
    a[x].sum=a[ls].sum+a[rs].sum;
}
void modify(int x,int l,int r,int value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].num=value;
        return;
    }
    updata(x);
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
int query(int x,int l,int r)
{
    updata(x);
    if (a[x].l==l && a[x].r==r)
        return(a[x].sum);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        return(query(ls,l,r));
    else if (l>mid)
        return(query(rs,l,r));
    else
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
            if (op==1)
            {
                int x;
                scanf("%d",&x);
                modify(1,l,r,x);
            }
            else
            {
                int sum=query(1,l,r),num=r-l+1,p=__gcd(sum,num);
                sum/=p,num/=p;
                if (num==1)
                    printf("%d\n",sum);
                else
                    printf("%d/%d\n",sum,num);
            }
        }
    }
    return(0);
}

