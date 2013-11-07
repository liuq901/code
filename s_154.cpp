#include <cstdio>
#include <cstdlib>
int main()
{
   int find(int);
   int q,x;
   scanf("%d",&q);
   x=find(q);
   if (x==-1)
      printf("No solution\n");
   else
      printf("%d\n",x);
   system("pause");
   return(0);
}
int find(int x)
{
   int count(int);
   int l,r,t,mid;
   if (x==0)
      return(1);
   l=1;
   r=400000015;
   while (l<=r)
   {
      mid=(l+r)/2;
      t=count(mid);
      if (t==x)
         return(mid-mid%5);
      else if (t<x)
         l=mid+1;
      else
         r=mid-1;
   }
   return(-1);
}
int count(int x)
{
   int s;
   s=0;
   while (x>=5)
   {
      s+=x/5;
      x/=5;
   }
   return(s);
}
