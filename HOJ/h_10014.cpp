#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int n,a[101][101],f[101][101]={0};
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
     for (int j=1;j<=i;j++)
        scanf("%d",&a[i][j]);
   f[1][1]=a[1][1];
   for (int i=2;i<=n;i++)
   {
      f[i][1]=f[i-1][1]+a[i][1];
      f[i][i]=f[i-1][i-1]+a[i][i];
      for (int j=2;j<=i-1;j++)
         f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      if (f[n][i]>ans)
         ans=f[n][i];
   printf("%d\n",ans);
}
