#include <cstdio>
#include <cstdlib>
int a[150001],b[150001],p[150001];
int main()
{
   void sort(int,int);
   int i,n;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&b[i],&a[i]);
      p[i]=i;
   }
   sort(1,n);
   for (i=1;i<=n;i++)
      printf("%d %d\n",b[i],a[i]);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   y=p[(l+r)/2];
   while (i<=j)
   {
      while (a[i]>x || a[i]==x && p[i]<y)
         i++;
      while (a[j]<x || a[j]==x && p[j]>y)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
