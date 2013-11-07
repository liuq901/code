#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      while (n<50025002)
         n+=2000;
      printf("%d\n",n-5);
   }
   system("pause");
   return(0);
}
