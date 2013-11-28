#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
set <int> s;
int a[100010];
int main()
{
   int n;
   scanf("%d",&n);
   int sum=0;
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      sum+=a[i];
      s.insert(sum);
   }
   int ans=0;
   sum=0;
   for (int i=n;i;i--)
   {
      sum+=a[i];
      ans+=s.count(sum);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
