#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10010],f[10010][30][30];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int ans=10000;
      memset(f,63,sizeof(f));
      f[1][0][0]=0;
      for (int i=1;i<=n;i++)
         for (int j=0;j<=m;j++)
            for (int k=0;k<=m-j;k++)
            {
               int p=n-i+j-k+1;
               if (i==p || i==p+1)
                  ans=min(ans,f[i][j][k]);
               if (f[i][j][k]>=ans)
                  continue;
               if (a[i]==a[p])
                  f[i+1][j][k]=min(f[i+1][j][k],f[i][j][k]);
               else
               {
                  f[i+1][j+1][k]=min(f[i+1][j+1][k],f[i][j][k]+1);
                  f[i][j][k+1]=min(f[i][j][k+1],f[i][j][k]+1);
               }
            }
      static int id=0;
      printf("Case %d: ",++id);
      if (ans==0)
         printf("Too easy\n");
      else if (ans==10000)
         printf("Too difficult\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
