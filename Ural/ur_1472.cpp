#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int b[100010],f[100010],a[100010][3];
int main()
{
   void dfs(int);
   int n;
   scanf("%d",&n);
   for (int i=2;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=i,a[i][1]=y,a[i][2]=b[x],b[x]=i;
   }
   for (int i=n;i;i--)
   {
      if (!b[i])
      {
         f[i]=1<<30;
         continue;
      }
      f[i]=0;
      for (int j=b[i];j;j=a[j][2])
      {
         int x=a[j][0];
         f[i]+=min(f[x],a[j][1]);
      }
   }
   printf("%d.00\n",f[1]);
   system("pause");
   return(0);
}
