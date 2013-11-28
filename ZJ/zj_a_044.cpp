#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%d\n",(n-1)*(n*n+n+6)/6+2);
   system("pause");
   return(0);
}
