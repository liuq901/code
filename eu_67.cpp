#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[110][110];
int main()
{
   int ans=0;
   for (int i=1;i<=100;i++)
      for (int j=1;j<=i;j++)
      {
         int x;
         scanf("%d",&x);
         f[i][j]=max(f[i-1][j-1],f[i-1][j])+x;
         ans=max(ans,f[i][j]);
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
