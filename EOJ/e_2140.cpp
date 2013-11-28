#include <cstdio>
#include <cstdlib>
int a[1010][1010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&x);
            a[i][j]+=x;
         }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            printf("%d%c",a[i][j],j==m?'\n':' ');
   }
   system("pause");
   return(0);
}
