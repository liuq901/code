#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%lld\n",(long long)n*n-n+2);
   system("pause");
   return(0);
}
