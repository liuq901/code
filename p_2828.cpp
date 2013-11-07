#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,s;
};
tree a[530000];
int p[200001],v[200001],ans[200001];
int main()
{
   void build(int,int,int),insert(int,int);
   int find(int,int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      build(1,1,n);
      for (int i=1;i<=n;i++)
         scanf("%d%d",&p[i],&v[i]);
      for (int i=n;i>=1;i--)
      {
         int pos=find(1,p[i]+1);
         ans[pos]=v[i];
         insert(1,pos);
      }
      for (int i=1;i<n;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r)
{
   a[x].l=l,a[x].r=r;
   if (l==r)
   {
      a[x].s=1;
      return;
   }
   int mid=l+r>>1,ls=x<<1,rs=ls+1;;
   build(ls,l,mid);
   build(rs,mid+1,r);
   a[x].s=a[ls].s+a[rs].s;
}
void insert(int x,int pos)
{
   if (a[x].l==a[x].r)
   {
      a[x].s=0;
      return;
   }
   int mid=a[x].l+a[x].r>>1,ls=x<<1,rs=ls+1;
   if (pos<=mid)
      insert(ls,pos);
   else
      insert(rs,pos);
   a[x].s=a[ls].s+a[rs].s;
}
int find(int x,int value)
{
   if (a[x].l==a[x].r)
      return(a[x].l);
   int ls=x<<1,rs=ls+1;
   if (value<=a[ls].s)
      return(find(ls,value));
   else
      return(find(rs,value-a[ls].s));
}
