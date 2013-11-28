#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m,a[110][110],b[110][110],c[110][110];
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&c[i][j]);
      ll ans=0;
      for (int i=1;i<=n;i++)
      {
         ll now=0;
         for (int j=1;j<=m;j++)
            now=max(now,ll(c[i][j])*min(a[i][j],b[i][j]));
         ans+=now;
      }
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
