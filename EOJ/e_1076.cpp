#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,x;
};
tree a[270000];
int n;
int main()
{
   void build(int,int,int),modify(int,int,int),print(int,int);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      build(1,1,n);
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         modify(1,x,y);
      }
      print(1,0);
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r)
{
   a[x].l=l,a[x].r=r,a[x].x=0;
   if (l==r)
      return;
   int ls=x<<1,rs=ls+1,mid=l+r>>1;
   build(ls,l,mid);
   build(rs,mid+1,r);
}
void modify(int x,int l,int r)
{
   if (l==a[x].l && r==a[x].r)
   {
      a[x].x++;
      return;
   }
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
}
void print(int x,int value)
{
   if (a[x].l==a[x].r)
   {
      printf("%d%c",value+a[x].x,a[x].l==n?'\n':' ');
      return;
   }
   int ls=x<<1,rs=ls+1;
   print(ls,value+a[x].x);
   print(rs,value+a[x].x);
}
