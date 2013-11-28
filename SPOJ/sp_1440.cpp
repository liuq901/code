#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      long long a;
      scanf("%lld",&a);
      for (long long m=a;m>=1;m--)
      {
         if ((a*a+1)%m)
            continue;
         long long n=(a*a+1)/m;
         printf("%lld\n",2*a+m+n);
         break;
      }
   }
   system("pause");
   return(0);
}
