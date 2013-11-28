#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,i,j,k,t;
   int a[10001];
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      scanf("%d",a+i);
   for (i=m;i>=1;i--)
   {
      k=n;
      while (a[k-1]>a[k])
         k--;
      j=n;
      while (a[k-1]>a[j])
         j--;
      t=a[k-1];
      a[k-1]=a[j];
      a[j]=t;
      j=n;
      while (k<j)
      {
         t=a[k];
         a[k]=a[j];
         a[j]=t;
         k++;
         j--;
      }
   }
   for (i=1;i<=n-1;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
