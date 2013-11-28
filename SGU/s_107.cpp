#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i;
   scanf("%d",&n);
   if (n<9)
      printf("0\n");
   else if (n==9)
      printf("8\n");
   else
   {
      printf("72");
      for (i=10;i<=n-1;i++)
         printf("0");
      printf("\n");
   }
   system("pause");
   return(0);
}
