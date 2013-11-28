#include <cstdio>
#include <set>
using namespace std;
set <int> a;
int main()
{
   int T,n;
   scanf("%d%d",&T,&n);
   while (T--)
   {
      a.clear();
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         a.insert(x);
      }
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         ans+=a.count(x);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
