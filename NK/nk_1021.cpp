#include <cstdio>
#include <cstdlib>
typedef long long ll;
int main()
{
   void print(ll);
   ll n;
   scanf("%lld",&n);
   print(n-1);
   system("pause");
   return(0);
}
void print(ll n)
{
   ll now=1;
   while (n)
   {
      if (n&1)
         printf("%lld\n",now);
      now*=3;
      n>>=1;
   }
}
