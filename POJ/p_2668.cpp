#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
   while (1)
   {
      int D,n;
      scanf("%d%d",&D,&n);
      if (!D && !n)
         break;
      ll ans=0;
      for (ll i=1;i<=n;)
      {
         ll l=i,r=n,p=(D+i-1)/i,t;
         while (l<=r)
         {
            ll mid=l+r>>1;
            if ((D+mid-1)/mid==p)
               l=mid+1,t=mid;
            else
               r=mid-1;
         }
         ans+=(t-i+1)*p;
         i=t+1;
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
