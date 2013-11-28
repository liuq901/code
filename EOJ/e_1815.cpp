#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
multiset <int> p;
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      p.insert(x);
   }
   int ans=0;
   for (int i=1;i<n;i++)
   {
      int x=*p.begin();
      p.erase(p.begin());
      int y=*p.begin();
      p.erase(p.begin());
      ans+=x+y;
      p.insert(x+y);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
