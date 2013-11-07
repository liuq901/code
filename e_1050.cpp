#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,a[101][101],b[101][101];
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
      int c[101][101]={0};
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
               c[i][j]+=a[i][k]*b[k][j];
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<n;j++)
            printf("%d ",c[i][j]);
         printf("%d\n",c[i][n]);
      }
   }
   system("pause");
   return(0);
}
