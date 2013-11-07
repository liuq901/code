#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (n==42)
         break;
      else
         printf("%d\n",n);
   }
   system("pause");
   return(0);
}
