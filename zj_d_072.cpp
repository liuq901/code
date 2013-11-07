#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,x;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      printf("Case %d: ",i);
      if (x%4==0 && x%100!=0 || x%400==0)
         printf("a leap year\n");
      else
         printf("a normal year\n");
   }
   system("pause");
   return(0);
}
