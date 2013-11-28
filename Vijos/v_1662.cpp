#include <cstdio>
#include <cstdlib>
int a[100001],b[100001];
int main()
{
   void sort(int,int,int *);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=n;i++)
      scanf("%d",&b[i]);
   sort(1,n,a);
   sort(1,n,b);
   int l1,l2,r1,r2;
   l1=l2=1,r1=r2=n;
   long long ans=0;
   for (int i=1;i<=m;i++)
      if (abs(a[l1]-b[r2])>abs(a[r1]-b[l2]))
      {
         ans+=abs(a[l1]-b[r2]);
         l1++,r2--;
      }
      else
      {
         ans+=abs(a[r1]-b[l2]);
         r1--,l2++;
      }
   printf("%I64d\n",ans);
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
