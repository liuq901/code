#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[1010][1010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=i;j++)
         {
            int x;
            scanf("%d",&x);
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+x;
            ans=max(ans,f[i][j]);
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
