#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[100010][3];
ll f[100010][3];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      f[1][0]=1LL<<60,f[1][1]=a[1][1],f[1][2]=a[1][1]+a[1][2];
      for (int i=2;i<=n;i++)
      {
         f[i][0]=min(f[i-1][0],f[i-1][1])+a[i][0];
         f[i][1]=min(min(f[i-1][0],f[i-1][1]),min(f[i-1][2],f[i][0]))+a[i][1];
         f[i][2]=min(min(f[i-1][1],f[i-1][2]),f[i][1])+a[i][2];
      }
      static int id=0;
      printf("%d. %lld\n",++id,f[n][1]);
   }
   system("pause");
   return(0);
}
