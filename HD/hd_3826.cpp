#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
   bool check(ll);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      ll n;
      cin>>n;
      static int id=0;
      printf("Case %d: %s\n",++id,!check(n)?"Yes":"No");
   }
   system("pause");
   return(0);
}
bool check(ll n)
{
   bool sqr(ll);
   if (sqr(n))
      return(true);
   for (ll i=2;i*i*i<=n;i++)
   {
      if (!(n%(i*i)))
         return(true);
      if (!(n%i) && sqr(n/i))
         return(true);
   }
   return(false);
}
bool sqr(ll n)
{
   ll l=2,r=1000000000;
   while (l<=r)
   {
      ll mid=l+r>>1;
      if (mid*mid==n)
         return(true);
      if (mid*mid<n)
         l=mid+1;
      else
         r=mid-1;
   }
   return(false);
}
