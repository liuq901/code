#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n<0)
      {
         printf("-1\n");
         break;
      }
      printf("%o\n",n);
   }
   system("pause");
   return(0);
}
