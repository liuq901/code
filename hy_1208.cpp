#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
typedef multiset <int>::iterator type;
const int q=1000000;
multiset <int> p;
int main()
{
   int flag=-1,n,ans=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      if (flag==-1)
      {
         p.insert(y);
         flag=x;
      }
      else if (x==flag)
         p.insert(y);
      else
      {
         type k;
         k=p.lower_bound(y);
         if (k==p.end())
         {
            k--;
            ans=(ans+(y-*k))%q;
            p.erase(k);
         }
         else if (k==p.begin())
         {
            ans=(ans+(*k-y))%q;
            p.erase(k);
         }
         else
         {
            type t=k;
            t--;
            if (y-*t<=*k-y)
            {
               ans=(ans+(y-*t))%q;
               p.erase(t);
            }
            else
            {
               ans=(ans+(*k-y))%q;
               p.erase(k);
            }
         }
         if (p.empty())
            flag=-1;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
