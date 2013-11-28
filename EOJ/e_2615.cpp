#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[310],b[310],c[310],f[410];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m=0;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
         a[i]++,b[i]++;
         m=max(m,b[i]);
      }
      for (int i=1;i<=m;i++)
      {
         f[i]=f[i-1];
         for (int j=1;j<=n;j++)
            if (b[j]==i)
               f[i]=max(f[i],f[a[j]-1]+c[j]);
      }
      printf("%d\n",f[m]);
   }
   system("pause");
   return(0);
}
