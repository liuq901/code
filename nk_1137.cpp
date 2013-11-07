#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[210],f[210][210],g[210][210];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=n+1;i<=n<<1;i++)
      a[i]=a[i-n];
   n<<=1;
   for (int i=2;i<=n;i++)
      a[i]+=a[i-1];
   memset(f,63,sizeof(f));
   memset(g,0,sizeof(g));
   for (int i=n;i;i--)
   {
      f[i][i]=g[i][i]=0;
      for (int j=i+1;j<=n;j++)
         for (int k=i;k<j;k++)
         {
            f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+a[j]-a[i-1]);
            g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]+a[j]-a[i-1]);
         }
   }
   int mi=1<<30,ma=0;
   n>>=1;
   for (int i=1;i<=n;i++)
   {
      mi=min(mi,f[i][i+n-1]);
      ma=max(ma,g[i][i+n-1]);
   }
   printf("%d\n%d\n",mi,ma);
   system("pause");
   return(0);
}
