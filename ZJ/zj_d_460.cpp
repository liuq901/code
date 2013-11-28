#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   if (n<=5)
      printf("0\n");
   else if (n<=11)
      printf("590\n");
   else if (n<=17)
      printf("790\n");
   else if (n<=59)
      printf("890\n");
   else
      printf("399\n");
   system("pause");
   return(0);
}
