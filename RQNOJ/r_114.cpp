#include <cstdio>
#include <cstdlib>
int main()
{
   long long n;
   bool flag=false;
   scanf("%I64d",&n);
   int i=2;
   while (n!=1)
      if (!(n%i))
      {
         if (flag)
            printf(" ");
         flag=true;
         printf("%d",i);
         n/=i;
      }
      else
         i++;
   printf("\n");
   system("pause");
   return(0);
}
