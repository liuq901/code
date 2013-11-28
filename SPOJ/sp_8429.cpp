#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct tree
{
   int max,min,x,l,r;
   bool change,in,de;
   void modify()
   {
      change=!change;
      min=-min,max=-max;
      swap(min,max);
      swap(in,de);
      x=-x;
   }
   void modify(int v)
   {
      min+=v,max+=v,x+=v;
   }
};
typedef const tree &node;
tree a[270000];
int b[100010];
int main()
{
   void build(int,int,int),modify(int,int,int,int);
   tree get(int,int,int);
   int n,Q;
   scanf("%d%d",&n,&Q);
   for (int i=1;i<=n;i++)
      scanf("%d",&b[i]);
   build(1,1,n);
   while (Q--)
   {
      int x,l,r;
      scanf("%d%d%d",&x,&l,&r);
      if (x)
         modify(1,l+1,r+1,x);
      else
      {
         tree tmp=get(1,l+1,r+1);
         printf("%d\n",tmp.in+(tmp.de<<1));
      }
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r)
{
   tree update(node,node);
   if (l==r)
   {
      a[x].l=l,a[x].r=r,a[x].x=0;
      a[x].min=a[x].max=b[l];
      a[x].in=a[x].de=true;
      a[x].change=false;
      return;
   }
   int ls=x<<1,rs=ls+1,mid=l+r>>1;
   build(ls,l,mid),build(rs,mid+1,r);
   a[x]=update(a[ls],a[rs]);
}
void modify(int x,int l,int r,int value)
{
   void updata(int);
   tree update(node,node);
   if (a[x].l==l && a[x].r==r)
   {
      a[x].modify();
      a[x].modify(value);
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
   a[x]=update(a[ls],a[rs]);
}
tree get(int x,int l,int r)
{
   void updata(int);
   tree update(node,node);
   if (l==a[x].l && r==a[x].r)
      return(a[x]);
   updata(x);
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      return(get(ls,l,r));
   else if (l>mid)
      return(get(rs,l,r));
   else
      return(update(get(ls,l,mid),get(rs,mid+1,r)));
}
void updata(int x)
{
   int ls=x<<1,rs=ls+1;
   if (a[x].change)
   {
      a[ls].modify();
      a[rs].modify();
      a[x].change=false;
   }
   if (a[x].x)
   {
      a[ls].modify(a[x].x);
      a[rs].modify(a[x].x);
      a[x].x=0;
   }
}
tree update(node a,node b)
{
   tree tmp;
   tmp.min=min(a.min,b.min);
   tmp.max=max(a.max,b.max);
   tmp.in=a.in && b.in && a.max<=b.min;
   tmp.de=a.de && b.de && a.min>=b.max;
   tmp.x=0;
   tmp.change=false;
   tmp.l=a.l,tmp.r=b.r;
   return(tmp);
}
