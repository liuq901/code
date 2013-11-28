#include <cstdio>
#include <cstdlib>
int a[30001];
int main()
{
   void sort(int,int);
   int w,n,i,j,ans;
   scanf("%d",&w);
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(1,n);
   ans=0;
   i=1;
   j=n;
   while (i<=j)
   {
      if (i==j)
      {
         ans++;
         break;
      }
      if (a[i]+a[j]<=w)
      {
         i++;
         j--;
         ans++;
      }
      else
      {
         j--;
         ans++;
      }
   }
   printf("%d\n",ans);
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
         t=a[i];
         a[i]=a[j];
         a[j]=t;
         i++;
         j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
