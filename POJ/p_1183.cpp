#include <cstdio>
#include <cstdlib>
int main()
{
   long long a;
   scanf("%I64d",&a);
   for (long long m=a;m>=1;m--)
   {
      if ((a*a+1)%m)
         continue;
      long long n=(a*a+1)/m;
      printf("%I64d\n",2*a+m+n);
      break;
   }
   system("pause");
   return(0);
}
