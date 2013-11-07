#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      int s=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         s^=x;
      }
      if (s!=0)
         printf("Yes\n");
      else
         printf("No\n");
   }
   system("pause");
   return(0);
}
