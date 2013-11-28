#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      printf("%s\n",x>=y?"MMM BRAINS":"NO BRAINS");
   }
   system("pause");
   return(0);
}
