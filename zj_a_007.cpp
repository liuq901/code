#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int prime(int);
   int n;
   while (scanf("%d",&n)!=EOF)
      if (prime(n))
         printf("Ù|”µ\n");
      else
         printf("·ÇÙ|”µ\n");
   system("pause");
   return(0);
}
int prime(int x)
{
   int i,t;
   t=(int)(sqrt(x)+0.5);
   for (i=2;i<=t;i++)
      if (x%i==0)
         return(0);
   return(1);
}
