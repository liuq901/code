#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1001][1001],b[1010][1010];
int main()
{
   int n,m,i,j;
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         scanf("%d",&a[i][j]);
   memset(b,26,sizeof(b));
   for (i=m;i>=1;i--)
      for (j=n;j>=1;j--)
      {
         if (a[j][i]<b[j][i])
            b[j][i]=a[j][i];
         if (b[j+1][i]<b[j][i])
            b[j][i]=b[j+1][i];
         if (b[j-1][i+1]<b[j][i])
            b[j][i]=b[j-1][i+1];
         if (b[j][i+1]<b[j][i])
            b[j][i]=b[j][i+1];
      }
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=m-1;j++)
         printf("%d ",b[i][j]);
      printf("%d\n",b[i][m]);
   }
   system("pause");
   return(0);
}
