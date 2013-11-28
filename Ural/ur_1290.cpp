#include <cstdio>
#include <cstdlib>
int a[25001];
int main()
{
   void sort(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(1,n);
   for (int i=1;i<=n;i++)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]>x)
         i++;
      while (a[j]<x)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
