#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x,n,m;
      x=0;
      scanf("%d%d",&n,&m);
      while (n--)
      {
         int y;
         scanf("%d",&y);
         x^=y%(m+1);
      }
      printf("%s\n",x?"Win":"Lost");
   }
   system("pause");
   return(0);
}
