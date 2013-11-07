#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      if (n<=10)
         printf("%d\n",6*n);
      else if (n<=20)
         printf("%d\n",60+2*(n-10));
      else if (n<=40)
         printf("%d\n",80+n-20);
      else
         printf("100\n");
   }
   system("pause");
   return(0);
}
