#include <cstdio>
#include <cstdlib>
int n,a[15001];
int main()
{
   int search(int);
   int m,i,s,x;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   s=0;
   scanf("%d",&m);
   for (i=1;i<=m;i++)
   {
      scanf("%d",&x);
      s+=search(x);
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
int search(int x)
{
   int l,r,mid;
   l=1;
   r=n;
   while (l<=r)
   {
      mid=(l+r)/2;
      if (a[mid]==x)
         return(1);
      if (a[mid]<x)
         l=mid+1;
      else
         r=mid-1;
   }
   return(0);
}
