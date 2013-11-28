#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%I64d\n\n",(long long)n*(n+1)/2);
   system("pause");
   return(0);
}
