#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      n++;
      ll ans=0;
      int p=1;
      while (p<=n)
      {
         p<<=1;
         ans+=(n/p)*(p>>1)+max(n%p-(p>>1),0);
      }
      printf("%lld\n",ans%1000000000);
   }
   system("pause");
   return(0);
}
