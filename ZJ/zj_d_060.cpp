#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   if (n<=25)
      n=25-n;
   else
      n=85-n;
   printf("%d\n",n);
   system("pause");
   return(0);
}
