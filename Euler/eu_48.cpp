#include <cstdio>
#include <cstdlib>
typedef long long ll;
const ll mod=10000000000LL;
int main()
{
   ll calc(int,int);
   ll ans=0;
   for (int i=1;i<=1000;i++)
      ans=(ans+calc(i,i))%mod;
   printf("%lld\n",ans);
   system("pause");
   return(0);
}
ll calc(int x,int t)
{
   ll work(ll);
   if (!x)
      return(1);
   ll ret=calc(x>>1,t);
   ret=work(ret);
   if (x&1)
      ret*=t;
   return(ret%mod);
}
ll work(ll x)
{
   ll a=x>>16,b=x&(1<<16)-1;
   return(x*a%mod*(1<<16)+x*b%mod);
}
