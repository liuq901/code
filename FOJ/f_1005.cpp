#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[210],f[210][40],s[210][210];
int main()
{
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
      {
         s[i][i]=0;
         for (int j=i+1;j<=n;j++)
            s[i][j]=s[i][j-1]+a[j]-a[i+j>>1];
      }
      memset(f,63,sizeof(f));
      for (int i=1;i<=n;i++)
         f[i][1]=s[1][i];
      for (int i=1;i<=n;i++)
         for (int j=2;j<=min(i,m);j++)
            for (int k=1;k<i;k++)
               f[i][j]=min(f[k][j-1]+s[k+1][i],f[i][j]);
      static int id=0;
      printf("Chain %d\nTotal distance sum = %d\n\n",++id,f[n][m]);
   }
   system("pause");
   return(0);
}
