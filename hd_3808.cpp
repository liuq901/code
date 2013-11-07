#include <cstdio>
#include <cstdlib>
const char ans[11][20]={"","Yu Jian","Tin O O","I Missed","Stefanie","The Same","About","Honey Honey","Unfinished","Hey Jude","When Winter Fades"};
int main()
{
   printf("Best wishes to Stefanie\n\n");
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      n%=14;
      if (n<=5)
         printf("%s\n",ans[n]);
      else
         printf("%s\n",ans[n-2]);
   }
   system("pause");
   return(0);
}
