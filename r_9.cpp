#include <cstdio>
#include <cstdlib>
int w[50001],a[50001];
int main()
{
   void sort(int,int);
   void change(int,int);
   int n,k,i,j;
   int e[11];
   scanf("%d%d",&n,&k);
   if (k==0 || n==0)
   {
      printf(" \n");
      goto last;
   }
   for (i=1;i<=10;i++)
      scanf("%d",&e[i]);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&w[i]);
      a[i]=i;
   }
   sort(1,n);
   i=1;
   j=2;
   while (i<=n)
      if (w[i]==w[j])
         j++;
      else
      {
         if (i!=j-1)
            change(i,j-1);
         i=j;
         j++;
      }
   for (i=1;i<=n;i++)
      w[i]+=e[(i-1)%10+1];
   sort(1,n);
   i=1;
   j=2;
   while (i<=n)
      if (w[i]==w[j])
         j++;
      else
      {
         if (i!=j-1)
            change(i,j-1);
         i=j;
         j++;
      }
   for (i=1;i<=k-1;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[k]);
last:
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=w[(l+r)/2];
   while (i<=j)
   {
      while (w[i]>x)
         i++;
      while (w[j]<x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=w[i],w[i]=w[j],w[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void change(int l,int r)
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
         t=w[i],w[i]=w[j],w[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      change(i,r);
   if (l<j)
      change(l,j);
}
