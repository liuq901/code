#include <cstdio>
#include <cstdlib>
int a[501][501],b[501][501];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         for (int j=1;j<=n;j++)
            scanf("%d",&a[x][j]);
         a[x][0]=1;
      }
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         for (int j=1;j<=n;j++)
         {
            int y;
            scanf("%d",&y);
            b[x][y]=j;
         }
         b[x][0]=0;
      }
      for (int i=1;i<=n;i++)
      {
         int x=i;
         while (1)
         {
            int k=a[x][a[x][0]];
            if (!b[k][0])
            {
               b[k][0]=x;
               break;
            }
            int y=b[k][0];
            if (b[k][x]<b[k][y])
            {
               a[y][0]++;
               b[k][0]=x;
               x=y;
            }
            else
               a[x][0]++;
         }
      }
      for (int i=1;i<=n;i++)
         printf("%d %d\n",i,b[i][0]);
   }
   system("pause");
   return(0);
}
