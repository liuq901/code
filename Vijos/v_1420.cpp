#include <cstdio>
#include <cstdlib>
const int mod=19900801;
int f[3001][3001];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      f[i][0]=1;
   for (int i=1;i<=m;i++)
      f[0][i]=1;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
   printf("%d\n",f[n][m]);
   system("pause");
   return(0);
}
