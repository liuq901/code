#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
set <int> a;
int dep[300001],l[300001],r[300001];
int main()
{
   int n;
   scanf("%d",&n);
   long long sum=0;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      set <int>::iterator pre,next;
      next=a.upper_bound(x);
      pre=next;
      if (next!=a.begin())
         pre--;
      if (a.empty())
         dep[x]=1;
      else if (next==a.begin() || next!=a.end() && r[*pre])
      {
         l[*next]=x;
         dep[x]=dep[*next]+1;
      }
      else
      {
         if (next==a.end())
         {
            pre=next;
            pre--;
         }
         r[*pre]=x;
         dep[x]=dep[*pre]+1;
      }
      a.insert(x);
      sum+=dep[x]-1;
      printf("%lld\n",sum);
   }
   system("pause");
   return(0);
}
