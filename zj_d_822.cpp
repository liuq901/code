#include <cstdio>
#include <cstdlib>
const int mod=1000000;
bool f[3010][3010];
int a[2][3010];
int main()
{
   int n,m,T;
   scanf("%d%d%d",&n,&m,&T);
   for (int i=1;i<=T;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      f[x][y]=true;
   }
   a[0][1]=1;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (f[i][j])
         {
            a[i&1][j]=0;
            continue;
         }
         a[i&1][j]=(a[i-1&1][j]+a[i&1][j-1])%mod;
      }
   printf("%d\n",a[n&1][m]);
   system("pause");
   return(0);
}
