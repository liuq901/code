#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%d\n",n&1?n-1:n);
   system("pause");
   return(0);
}
