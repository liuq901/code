#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,k,x;
   int a[11];
   scanf("%d",&k);
   for (i=1;i<=k;i++)
   {
      scanf("%d",&n);
      scanf("%d",&a[i]);
      for (j=1;j<=n;j++)
         scanf("%d",&x);
   }
   for (i=1;i<=k;i++)
      if (a[i])
         printf("lolanv\n");
      else
         printf("wind\n");
   system("pause");
   return(0);
}
