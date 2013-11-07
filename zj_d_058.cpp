#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      if (n<0)
         printf("-1\n");
      if (n>0)
         printf("1\n");
      if (n==0)
         printf("0\n");
   }
   system("pause");
   return(0);
}
