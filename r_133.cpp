#include <cstdio>
#include <cstdlib>
int a[200001];
int main()
{
   void sort(int,int);
   int n,i,x,s;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(1,n);
   s=1;
   x=a[1];
   for (i=2;i<=n;i++)
   {
      if (a[i]==x)
      {
         s++;
         continue;
      }
      printf("%d %d\n",x,s);
      x=a[i];
      s=1;
   }
   printf("%d %d\n",x,s);
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
