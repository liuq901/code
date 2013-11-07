#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,min=2000000,max=0;
      scanf("%d",&n);
      while (n--)
      {
         int x;
         scanf("%d",&x);
         if (x<min)
            min=x;
         if (x>max)
            max=x;
      }
      printf("%d\n",(max-min)*2);
   }
   system("pause");
   return(0);
}
