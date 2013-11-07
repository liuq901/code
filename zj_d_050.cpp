#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      n-=15;
      if (n<0)
         n+=24;
      printf("%d\n",n);
   }
   system("pause");
   return(0);
}
