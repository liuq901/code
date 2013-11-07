#include <cstdio>
#include <cstdlib>
int main()
{
   void sort(int,int,int *);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,a[1001],b[1001];
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
         scanf("%d",&b[i]);
      sort(1,n,a);
      sort(1,n,b);
      int ans=0;
      for (int i=1;i<=n;i++)
         ans+=a[i]*b[i];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r,int *a)
{
   int i,j,x;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a);
   if (l<j)
      sort(l,j,a);
}
