#include <cstdio>
struct tree
{
    int l,r,sum;
};
tree a[530000];
void build(int x,int l,int r)
{
    a[x].l=l,a[x].r=r,a[x].sum=0;
    if (l==r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void modify(int x,int pos,int value)
{
    a[x].sum+=value;
    if (a[x].l==a[x].r)
        return;
    int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
    pos<=mid?modify(ls,pos,value):modify(rs,pos,value);
}
int query(int x,int num)
{
    if (a[x].l==a[x].r)
        return(a[x].l);
    int ls=x<<1,rs=ls+1;
    return(num<=a[ls].sum?query(ls,num):query(rs,num-a[ls].sum));
}
int v[150010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        build(1,1,n+Q);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
            modify(1,i,1);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            char op[10];
            int x;
            scanf("%s%d",op,&x);
            if (op[0]=='a')
            {
                v[++n]=x;
                modify(1,n,1);
            }
            else if (a[1].sum<x)
                printf("none\n");
            else
            {
                int pos=query(1,x);
                printf("%d\n",v[pos]);
                modify(1,pos,-1);
            }
        }
    }
    return(0);
}

