#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,maxl,maxr,max,sum;
};
tree a[1100000];
int v[500001];
int main()
{
   void build(int,int,int),modify(int,int,int);
   int count(int,int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&v[i]);
   build(1,1,n);
   for (int i=1;i<=m;i++)
   {
      int p,x,y;
      scanf("%d%d%d",&p,&x,&y);
      if (p==1)
      {
         if (x>y)
         {
            int t;
            t=x,x=y,y=t;
         }
         printf("%d\n",count(1,x,y));
      }
      else
         modify(1,x,y);
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r)
{
   void update(int);
   a[x].l=l,a[x].r=r;
   if (l==r)
   {
      a[x].maxl=a[x].maxr=a[x].max=a[x].sum=v[l];
      return;
   }
   int ls=x<<1,rs=ls+1,mid=l+r>>1;
   build(ls,l,mid);
   build(rs,mid+1,r);
   update(x);
}
void modify(int x,int pos,int value)
{
   void update(int);
   if (a[x].l==a[x].r)
   {
      a[x].maxl=a[x].maxr=a[x].max=a[x].sum=value;
      return;
   }
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   if (pos<=mid)
      modify(ls,pos,value);
   else
      modify(rs,pos,value);
   update(x);
}
void update(int x)
{
   int max(int,int);
   int ls=x<<1,rs=ls+1;
   a[x].sum=a[ls].sum+a[rs].sum;
   a[x].max=max(max(a[ls].max,a[rs].max),a[ls].maxr+a[rs].maxl);
   a[x].maxl=max(a[ls].maxl,a[rs].maxl+a[ls].sum);
   a[x].maxr=max(a[rs].maxr,a[ls].maxr+a[rs].sum);
}
int count(int x,int l,int r)
{
   int max(int,int),maxl(int,int,int),maxr(int,int,int);
   if (l==a[x].l && r==a[x].r)
      return(a[x].max);
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      return(count(ls,l,r));
   else if (l>mid)
      return(count(rs,l,r));
   else
      return(max(max(count(ls,l,mid),count(rs,mid+1,r)),maxl(rs,mid+1,r)+maxr(ls,l,mid)));
}
int maxl(int x,int l,int r)
{
   int max(int,int),sum(int,int,int);
   if (l==a[x].l && r==a[x].r)
      return(a[x].maxl);
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      return(maxl(ls,l,r));
   else if (l>mid)
      return(maxl(rs,l,r));
   else
      return(max(maxl(ls,l,mid),sum(ls,l,mid)+maxl(rs,mid+1,r)));
}
int maxr(int x,int l,int r)
{
   int max(int,int),sum(int,int,int);
   if (l==a[x].l && r==a[x].r)
      return(a[x].maxr);
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      return(maxr(ls,l,r));
   else if (l>mid)
      return(maxr(rs,l,r));
   else
      return(max(maxr(rs,mid+1,r),sum(rs,mid+1,r)+maxr(ls,l,mid)));
}
int max(int x,int y)
{
   return(x>y?x:y);
}
int sum(int x,int l,int r)
{
   if (l==a[x].l && r==a[x].r)
      return(a[x].sum);
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      return(sum(ls,l,r));
   else if (l>mid)
      return(sum(rs,l,r));
   else
      return(sum(ls,l,mid)+sum(rs,mid+1,r));
}
