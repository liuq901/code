#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,a[201][201];
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      memset(a,-26,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (z>a[x][y])
            a[x][y]=z;
      }
      for (int k=1;k<=n;k++)
         for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
               if (a[i][k]+a[k][j]>a[i][j])
                  a[i][j]=a[i][k]+a[k][j];
      int t;
      scanf("%d",&t);
      while (t--)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         printf("%d\n",a[x][y]>=0?a[x][y]:-1);
      }
   }
   system("pause");
   return(0);
}
