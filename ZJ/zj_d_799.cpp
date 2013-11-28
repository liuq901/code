#include <cstdio>
#include <cstdlib>
typedef long long ll;
struct tree
{
   int l,r,s;
   ll x,k;
};
tree a[1100000];
int v[500010];
int main()
{
   void build(int,int,int),modify(int,int,int,int);
   ll find(int,int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&v[i]);
   build(1,1,n);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int op,l,r;
      scanf("%d%d%d",&op,&l,&r);
      if (op==1)
      {
         int x;
         scanf("%d",&x);
         modify(1,l,r,x);
      }
      else
         printf("%lld\n",find(1,l,r));
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r)
{
   a[x].l=l,a[x].r=r,a[x].s=r-l+1,a[x].k=0;
   if (l==r)
   {
      a[x].x=v[l];
      return;
   }
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   build(ls,l,mid);
   build(rs,mid+1,r);
   a[x].x=a[ls].x+a[rs].x;
}
void modify(int x,int l,int r,int value)
{
   if (a[x].l==l && a[x].r==r)
   {
      a[x].k+=value;
      return;
   }
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   a[ls].k+=a[x].k,a[rs].k+=a[x].k,a[x].k=0;
   if (r<=mid)
      modify(ls,l,r,value);
   else if (l>mid)
      modify(rs,l,r,value);
   else
   {
      modify(ls,l,mid,value);
      modify(rs,mid+1,r,value);
   }
   a[x].x=a[ls].x+a[ls].k*a[ls].s+a[rs].x+a[rs].k*a[rs].s;
}
ll find(int x,int l,int r)
{
   if (a[x].l==l && a[x].r==r)
      return(a[x].x+a[x].k*a[x].s);
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   a[ls].k+=a[x].k,a[rs].k+=a[x].k,a[x].x+=a[x].k*a[x].s,a[x].k=0;
   if (r<=mid)
      return(find(ls,l,r));
   else if (l>mid)
      return(find(rs,l,r));
   return(find(ls,l,mid)+find(rs,mid+1,r));
}
