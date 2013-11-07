#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      if (!n)
      {
         printf("1\n");
         continue;
      }
      if (n==1)
      {
         printf("0\n");
         continue;
      }
      if (n&1)
         printf("4");
      for (int i=1;i<=n>>1;i++)
         printf("8");
      printf("\n");
   }
   system("pause");
   return(0);
}
