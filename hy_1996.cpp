#include <cstdio>
#include <cstdlib>
const int m=19650827;
int a[1001],f[1001][1001],g[1001][1001];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=n;i>=1;i--)
      for (int j=i;j<=n;j++)
      {
         if (i==j)
         {
            f[i][j]=1;
            continue;
         }
         if (a[i]<a[i+1])
            f[i][j]=(f[i][j]+f[i+1][j])%m;
         if (a[i]<a[j])
            f[i][j]=(f[i][j]+g[i+1][j])%m;
         if (a[j]>a[j-1])
            g[i][j]=(g[i][j]+g[i][j-1])%m;
         if (a[j]>a[i])
            g[i][j]=(g[i][j]+f[i][j-1])%m;
      }
   printf("%d\n",(f[1][n]+g[1][n])%m);
   system("pause");
   return(0);
}
