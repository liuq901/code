#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool a[110][110],b[110][110];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      int ia,ib,da,db;
      scanf("%d%d%d%d",&ia,&ib,&da,&db);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
         {
            if (a[i][j] && !b[i][j])
               ans+=min(da,ib);
            if (!a[i][j] && b[i][j])
               ans+=min(ia,db);
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
