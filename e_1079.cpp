#include <cstdio>
#include <cstdlib>
int main()
{
   int a[31][31];
   for (int i=1;i<=30;i++)
   {
      a[i][1]=a[i][i]=1;
      for (int j=2;j<=i-1;j++)
         a[i][j]=a[i-1][j-1]+a[i-1][j];
   }
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=i-1;j++)
            printf("%d ",a[i][j]);
         printf("%d\n",a[i][i]);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
