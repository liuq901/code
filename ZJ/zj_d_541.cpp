#include <cstdio>
#include <cstdlib>
typedef long long ll;
const ll mod=1234567;
int main()
{
   ll calc(int);
   int n;
   while (scanf("%d",&n)==1)
      printf("%lld\n",calc(n-1));
   system("pause");
   return(0);
}
ll calc(int n)
{
   if (n<0)
      return(0);
   if (!n)
      return(1);
   ll ans=calc(n>>1);
   ans*=ans;
   if (n&1)
      ans<<=1;
   return(ans%mod);
}
