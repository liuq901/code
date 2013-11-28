#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%.3lf\n",(n-32)/9.0*5);
   system("pause");
   return(0);
}
