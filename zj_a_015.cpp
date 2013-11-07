#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,i,j;
   int a[101][101];
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      for (i=1;i<=n;i++)
         for (j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      for (i=1;i<=m;i++)
         for (j=1;j<=n;j++)
         {
            printf("%d",a[j][i]);
            if (j==n)
               printf("\n");
            else
               printf(" ");
         }
   }
   system("pause");
   return(0);
}
