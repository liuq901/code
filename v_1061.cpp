#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[5001],f[1001][5001];
int main()
{
   int i,j,n,m;
   scanf("%d%d",&m,&n);
   for (i=n;i>=1;i--)
      scanf("%d",&a[i]);
   memset(f,0,sizeof(f));
   for (i=1;i<=m;i++)
      for (j=3*i;j<=n;j++)
      {
         if (j==3*i)
         {
            f[i][j]=f[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]);
            continue;
         }
         if (f[i][j-1]<f[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]))
            f[i][j]=f[i][j-1];
         else
            f[i][j]=f[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]);
      }
   printf("%d\n",f[m][n]);
   system("pause");
   return(0);
}
