#include <cstdio>
#include <cstdlib>
int a[50001],b[50001];
int main()
{
   void sort(int,int);
   int n,i,min,max;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&a[i],&b[i]);
   sort(1,n);
   min=a[1],max=b[1];
   for (i=2;i<=n;i++)
   {
      if (a[i]>max)
      {
         printf("%d %d\n",min,max);
         min=a[i],max=b[i];
         continue;
      }
      if (b[i]>max)
         max=b[i];
   }
   printf("%d %d\n",min,max);
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
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
