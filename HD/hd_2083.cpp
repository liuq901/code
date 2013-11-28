#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[510];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      int x=a[n+1>>1],ans=0;
      for (int i=1;i<=n;i++)
         ans+=abs(x-a[i]);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
