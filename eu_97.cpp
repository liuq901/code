#include <cstdio>
#include <cstdlib>
typedef long long ll;
const ll mod=10000000000LL;
int main()
{
   ll calc(int);
   printf("%lld\n",(calc(7830457)*28433+1)%mod);
   system("pause");
   return(0);
}
ll calc(int x)
{
   ll work(ll);
   if (!x)
      return(1);
   ll ret=calc(x>>1);
   ret=work(ret);
   if (x&1)
      ret<<=1;
   return(ret%mod);
}
ll work(ll x)
{
   ll a=x>>16,b=x&(1<<16)-1;
   return(x*a%mod*(1<<16)+x*b%mod);
}
