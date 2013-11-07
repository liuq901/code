#include <cstdio>
#include <cstdlib>
int main()
{
   long long i,n;
   scanf("%I64d",&n);
   i=1;
   while (1)
   {
      i*=9;
      if (i>=n)
      {
         printf("181818181818\n");
         break;
      }
      i*=2;
      if (i>=n)
      {
         printf("ZBT\n");
         break;
      }
   }
   system("pause");
   return(0);
}
