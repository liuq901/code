#include <cstdio>
#include <cstdlib>
int a[10001];
int main()
{
   void sort(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(1,n);
      long long ans=0;
      for (int i=1;i<=n;i++)
         ans+=(long long)a[i]*(i-1);
      printf("%I64d\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
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
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
