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
      printf("%d\n",n&-n);
   }
   system("pause");
   return(0);
}
