#include <cstdio>
#include <cstdlib>
int a[30001];
int main()
{
   void sort(int,int);
   int i,n,w,s,l,r;
   scanf("%d",&w);
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(1,n);
   l=1;
   r=n;
   s=0;
   while (1)
   {
      if (l==r)
         s++;
      if (l>=r)
         break;
      if (a[l]+a[r]<=w)
      {
         l++;
         r--;
      }
      else
         r--;
      s++;
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
