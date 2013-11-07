#include <cstdio>
#include <cstdlib>
int k,x[10001],y[10001];
int main()
{
   void sort(int,int,int[]);
   int a,n,i,j,ans,min;
   int b[10001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&x[i],&y[i]);
   sort(1,n,y);
   k=y[(n+1)/2];
   ans=0;
   for (i=1;i<=n;i++)
      ans+=abs(y[i]-k);
   sort(1,n,x);
   min=200000000;
   for (i=1;i<=n;i++)
   {
      a=0;
      for (j=1;j<=n;j++)
         b[j]=x[i]+j-i;
      for (j=1;j<=n;j++)
         a+=abs(x[j]-b[j]);
      if (a<min)
         min=a;
   }
   ans+=min;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r,int a[])
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
      sort(i,r,a);
   if (l<j)
      sort(l,j,a);
}
