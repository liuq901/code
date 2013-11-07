#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%*d");
      for (int i=1;i<n;i++)
         printf("%d ",i);
      printf("%d\n",n);
   }
   system("pause");
   return(0);
}
