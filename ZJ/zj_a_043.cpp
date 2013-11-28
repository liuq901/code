#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%d\n",(n*n+n+2)/2);
   system("pause");
   return(0);
}
