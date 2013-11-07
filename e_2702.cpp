#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct tree
{
   int l,r,x;
};
tree a[530000];
int main()
{
   void build(int,int,int,int);
   int get(int,int);
   int h,w,n;
   scanf("%d%d%d",&h,&w,&n);
   build(1,1,min(h,n),w);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      printf("%d\n",get(1,x));
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r,int value)
{
   a[x].l=l,a[x].r=r,a[x].x=value;
   if (l==r)
      return;
   int ls=x<<1,rs=ls+1,mid=l+r>>1;
   build(ls,l,mid,value);
   build(rs,mid+1,r,value);
}
int get(int x,int value)
{
   if (a[x].x<value)
      return(-1);
   if (a[x].l==a[x].r)
   {
      a[x].x-=value;
      return(a[x].l);
   }
   int ls=x<<1,rs=ls+1,mid=a[x].l+a[x].r>>1,ans;
   ans=a[ls].x>=value?get(ls,value):get(rs,value);
   a[x].x=max(a[ls].x,a[rs].x);
   return(ans);
}
