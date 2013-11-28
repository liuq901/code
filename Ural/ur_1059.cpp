#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   printf("0\n");
   for (int i=1;i<=n;i++)
      printf("X\n*\n%d\n+\n",i);
   system("pause");
   return(0);
}
