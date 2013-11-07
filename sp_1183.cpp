#include <cstdio>
#include <cstdlib>
const int q=98777;
int main()
{
   long long count(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      printf("%lld\n",count(n*n-2*n+1));
   }
   system("pause");
   return(0);
}
long long count(int x)
{
   if (!x)
      return(1);
   long long p=count(x>>1);
   if (x&1)
      return(p*p*2%q);
   else
      return(p*p%q);
}
