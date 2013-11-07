#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
      for (int i=2;i<=n;i++)
      {
         if (n%i)
            continue;
         printf("%d %d\n",i,n/i);
         break;
      }
   system("pause");
   return(0);
}
