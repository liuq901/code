#include <cstdio>
#include <cstdlib>
#include <algorithm>
int a[100010],b[100010],f[100010];
using namespace std;
int main()
{
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=m;j++)
            scanf("%d",&a[j]);
         f[0]=0,f[1]=a[1];
         for (int j=2;j<=m;j++)
            f[j]=max(f[j-2]+a[j],f[j-1]);
         b[i]=f[m];
      }
      f[0]=0,f[1]=b[1];
      for (int i=2;i<=n;i++)
         f[i]=max(f[i-2]+b[i],f[i-1]);
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
