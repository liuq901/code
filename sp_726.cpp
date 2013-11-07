#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
multiset <int> a;
int main()
{
   int n;
   scanf("%d",&n);
   long long ans=0;
   for (int i=1;i<=n;i++)
   {
      int k;
      scanf("%d",&k);
      for (int j=1;j<=k;j++)
      {
         int x;
         scanf("%d",&x);
         a.insert(x);
      }
      multiset <int>::iterator p=a.end();
      p--;
      ans+=*p-*a.begin();
      a.erase(p);
      a.erase(a.begin());
   }
   printf("%lld\n",ans);
   system("pause");
   return(0);
}
