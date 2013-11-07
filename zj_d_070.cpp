#include <cstdio>
#include <cstdlib>
int main()
{
   int x;
   while (1)
   {
      scanf("%d",&x);
      if (x==0)
         break;
      if (x%4==0 && x%100!=0 || x%400==0)
         printf("a leap year\n");
      else
         printf("a normal year\n");
   }
   system("pause");
   return(0);
}
