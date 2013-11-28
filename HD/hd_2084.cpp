#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[110][110];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,ans=0;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=i;j++)
         {
            scanf("%d",&a[i][j]);
            a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
            ans=max(ans,a[i][j]);
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
