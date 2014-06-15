#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct tree
{
    int l,r,delta,value;
    ll first,sum;
};
tree a[530000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].first=a[x].sum=a[x].delta=0;
    a[x].value=-1;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void updata(int x)
{
    ll len=a[x].r-a[x].l+1;
    if (a[x].value!=-1)
        a[x].sum=a[x].value*len;
    a[x].sum+=(2*a[x].first+a[x].delta*(len-1))*len/2;
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        if (a[x].value!=-1)
        {
            a[ls].value=a[rs].value=a[x].value;
            a[ls].delta=a[rs].delta=a[x].delta;
            a[ls].first=a[x].first;
            a[rs].first=a[x].first+ll(a[ls].r-a[ls].l+1)*a[x].delta;
        }
        else
        {
            a[ls].delta+=a[x].delta;
            a[rs].delta+=a[x].delta;
            a[ls].first+=a[x].first;
            a[rs].first+=a[x].first+ll(a[ls].r-a[ls].l+1)*a[x].delta;
        }
    }
    a[x].value=-1;
    a[x].first=a[x].delta=0;
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(ls);
    updata(rs);
    a[x].sum=a[ls].sum+a[rs].sum;
}
void modify(int x,int l,int r,int first,int delta)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].first+=first;
        a[x].delta+=delta;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        modify(ls,l,r,first,delta);
    else if (l>mid)
        modify(rs,l,r,first,delta);
    else
    {
        modify(ls,l,mid,first,delta);
        modify(rs,mid+1,r,first+(mid-l+1)*delta,delta);
    }
    update(x);
}
void fill(int x,int l,int r,int value)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].value=value;
        a[x].first=a[x].delta=0;
        return;
    }
    updata(x);
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    if (r<=mid)
        fill(ls,l,r,value);
    else if (l>mid)
        fill(rs,l,r,value);
    else
    {
        fill(ls,l,mid,value);
        fill(rs,mid+1,r,value);
    }
    update(x);
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
    else
        return(query(ls,l,mid)+query(rs,mid+1,r));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        build(1,1,250000);
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='A')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                modify(1,l,r,1,1);
            }
            else if (op[0]=='B')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                modify(1,l,r,r-l+1,-1);
            }
            else if (op[0]=='C')
            {
                int l,r,x;
                scanf("%d%d%d",&l,&r,&x);
                fill(1,l,r,x);
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(1,l,r));
            }
        }
    }
    return(0);
}

