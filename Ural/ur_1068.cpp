#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   if (n>0)
      printf("%d\n",n*(n+1)/2);
   else
   {
      n*=-1;
      n=n*(n+1)/2;
      n*=-1;
      n++;
      printf("%d\n",n);
   }
   system("pause");
   return(0);
}
