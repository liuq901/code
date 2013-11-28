#include <cstdio>
#include <cstdlib>
int main()
{
   for (int i=1;i<=1000000;i++)
      printf("%c",rand()%26+'a');
   printf("\n");
   system("pause");
   return(0);
}
