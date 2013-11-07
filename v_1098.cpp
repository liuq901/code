#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,j,t,max;
   int a[101],b[101],c[101];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=n;i++)
   {
      b[i]=1;
      for (j=1;j<=i-1;j++)
         if (a[i]>a[j] && b[j]+1>b[i])
            b[i]=b[j]+1;
   }
   for (i=n;i>=1;i--)
   {
      c[i]=1;
      for (j=n;j>=i+1;j--)
         if (a[i]>a[j] && c[j]+1>c[i])
            c[i]=c[j]+1;
   }
   max=0;
   for (i=1;i<=n;i++)
      if (b[i]+c[i]>max)
         max=b[i]+c[i];
   printf("%d\n",n-max+1);
   system("pause");
   return(0);
}
