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
      if (x!=y && x!=y+2)
      {
         printf("No Number\n");
         continue;
      }
      printf("%d\n",x+y-(y&1));
   }
   system("pause");
   return(0);
}
