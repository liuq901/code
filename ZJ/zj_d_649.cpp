#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<n-i+1;j++)
            printf("_");
         for (int j=1;j<=i;j++)
            printf("+");
         printf("\n");
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
