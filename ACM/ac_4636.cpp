#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
typedef multiset <int>::iterator data;
multiset <int> a;
int main()
{
   bool check(int,int,int,int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      a.clear();
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         ans+=x;
         a.insert(x);
      }
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         data k=a.find(x);
         if (k==a.end())
            ans+=x;
         else
            a.erase(k);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
