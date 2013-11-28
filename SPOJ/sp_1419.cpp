#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   if (n%10)
      printf("1\n%d\n",n%10);
   else
      printf("2\n");
   system("pause");
   return(0);
}
