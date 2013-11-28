#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[500010],f[20][500010];
int main()
{
   int log(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      f[0][i]=a[i];
   }
   int limit=log(n);
   for (int i=1;i<=limit;i++)
      for (int j=1;j<=n;j++)
      {
         if (j+(1<<i)-1>n)
            break;
         f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
      }
   int m;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      if (x>y)
         swap(x,y);
      int t=log(y-x+1);
      printf("%d\n",max(f[t][x],f[t][y-(1<<t)+1]));
   }
   system("pause");
   return(0);
}
int log(int x)
{
   int ans=-1;
   while (x)
   {
      ans++;
      x>>=1;
   }
   return(ans);
}
