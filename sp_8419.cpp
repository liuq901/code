#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main()
{
   ll gcd(ll,ll);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      ll a,b,c,d;
      scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
      if (!a && !b || !c && !d)
         printf("%s\n",!a && !b && !c && !d?"YES":"NO");
      else
      {
         ll x=gcd(abs(a),abs(b)),y=gcd(abs(c),abs(d));
         if (y%x)
            printf("NO\n");
         else
         {
            while (y>x && !(y&1))
               y>>=1;
            printf("%s\n",x==y?"YES":"NO");
         }
      }
   }
   system("pause");
   return(0);
}
ll gcd(ll a,ll b)
{
   return(b?gcd(b,a%b):a);
}
