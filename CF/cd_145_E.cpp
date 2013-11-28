#include <cstdio>
#include <algorithm>
using namespace std;
struct tree
{
    int l,r,four,seven,big,small;
    bool change;
};
char s[1000010];
tree a[2100000];
void updata(int x)
{
    if (!a[x].change)
        return;
    a[x].change=false;
    if (a[x].l!=a[x].r)
    {
        int ls=x<<1,rs=ls+1;
        a[ls].change=!a[ls].change;
        a[rs].change=!a[rs].change;
    }
    swap(a[x].four,a[x].seven);
    swap(a[x].big,a[x].small);
}
void update(int x)
{
    int ls=x<<1,rs=ls+1;
    updata(x);
    updata(ls);
    updata(rs);
    a[x].four=a[ls].four+a[rs].four;
    a[x].seven=a[ls].seven+a[rs].seven;
    a[x].big=max(max(a[x].four,a[x].seven),max(a[ls].four+a[rs].big,a[ls].big+a[rs].seven));
    a[x].small=max(max(a[x].four,a[x].seven),max(a[ls].seven+a[rs].small,a[ls].small+a[rs].four));
}
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].change=false;
    if (l==r)
    {
        a[x].four=s[l]=='4';
        a[x].seven=s[l]=='7';
        a[x].big=a[x].small=1;
        return;
    }
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(x);
}
void modify(int x,int l,int r)
{
    if (a[x].l==l && a[x].r==r)
    {
        a[x].change=!a[x].change;
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
    update(x);
}
int main()
{
    int n,Q;
    scanf("%d%d%s",&n,&Q,s+1);
    build(1,1,n);
    while (Q--)
    {
        scanf("%s",s);
        if (s[0]=='c')
        {
            updata(1);
            printf("%d\n",a[1].big);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            modify(1,l,r);
        }
    }
    return(0);
}

