#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct tree
{
   int l,r,x;
};
tree a[270000];
int sum,ans;
int main()
{
   void build(int,int,int,int),modify(int,int),count(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int p;
      scanf("%d",&p);
      build(1,1,100000,p);
      int n;
      scanf("%d%*c",&n);
      while (n)
      {
         char ch;
         scanf("%c",&ch);
         if (ch=='b')
         {
            int t,x;
            scanf("%d%d%*c",&t,&x);
            for (int i=1;i<=t;i++)
               modify(1,x);
            n-=t;
         }
         else
         {
            int x=ch-'0';
            while (1)
            {
               scanf("%c",&ch);
               if (ch=='\n')
                  break;
               x=x*10+ch-'0';
            }
            modify(1,x);
            n--;
         }
      }
      sum=ans=0;
      count(1,p);
      printf("%d %d\n",sum,ans);
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
void modify(int x,int value)
{
   if (a[x].l==a[x].r)
   {
      a[x].x-=value;
      return;
   }
   int ls=x<<1,rs=ls+1;
   if (value<=a[ls].x)
      modify(ls,value);
   else
      modify(rs,value);
   a[x].x=max(a[ls].x,a[rs].x);
}
void count(int x,int value)
{
   if (a[x].l==a[x].r)
   {
      if (a[x].x!=value)
      {
         sum++;
         ans+=a[x].x;
      }
      return;
   }
   int ls=x<<1,rs=ls+1;
   count(ls,value),count(rs,value);
}
