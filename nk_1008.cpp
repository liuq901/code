#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[1010];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i].second,&a[i].first);
      if (a[i].second>a[i].first)
         swap(a[i].second,a[i].first);
   }
   sort(a+1,a+n+1);
   int ans=0,now=-1<<30;
   for (int i=1;i<=n;i++)
      if (a[i].second>=now)
      {
         ans++;
         now=a[i].first;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
