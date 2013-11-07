#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
      printf("'C' can use printf(\"%%d\",n); to show integer like %d\n",n);
   system("pause");
   return(0);
}
