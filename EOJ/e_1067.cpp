#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x,n;
      x=0;
      scanf("%d",&n);
      while (n--)
      {
         int y;
         scanf("%d",&y);
         x^=y;
      }
      printf("%s\n",x?"Win":"Lost");
   }
   system("pause");
   return(0);
}
