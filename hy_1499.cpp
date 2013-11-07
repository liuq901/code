#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=1000000000;
int f[201][201][201];
int main()
{
   int n,m,x0,y0,p,q[2][201];
   bool a[201][201];
   scanf("%d%d%d%d%d%*c",&n,&m,&x0,&y0,&p);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         a[i][j]=ch=='.';
      }
      scanf("%*c");
   }
   memset(f,-26,sizeof(f));
   f[0][x0][y0]=0;
   for (int k=1;k<=p;k++)
   {
      int x,y,z,l,r;
      scanf("%d%d%d",&x,&y,&z);
      switch (z)
      {
      case 1:
         for (int j=1;j<=m;j++)
         {
            l=1,r=0;
            for (int i=n;i>=1;i--)
            {
               if (!a[i][j])
               {
                  l=1,r=0;
                  f[k][i][j]=-inf;
                  continue;
               }
               if (l<=r && q[1][l]-i>y-x+1)
                  l++;
               while (l<=r && f[k-1][i][j]+i>q[0][r])
                  r--;
               q[0][++r]=f[k-1][i][j]+i;
               q[1][r]=i;
               f[k][i][j]=q[0][l]-i;
            }
         }
         break;
      case 2:
         for (int j=1;j<=m;j++)
         {
            l=1,r=0;
            for (int i=1;i<=n;i++)
            {
               if (!a[i][j])
               {
                  l=1,r=0;
                  f[k][i][j]=-inf;
                  continue;
               }
               if (l<=r && i-q[1][l]>y-x+1)
                  l++;
               while (l<=r && f[k-1][i][j]-i>q[0][r])
                  r--;
               q[0][++r]=f[k-1][i][j]-i;
               q[1][r]=i;
               f[k][i][j]=q[0][l]+i;
            }
         }
         break;
      case 3:
         for (int i=1;i<=n;i++)
         {
            l=1,r=0;
            for (int j=m;j>=1;j--)
            {
               if (!a[i][j])
               {
                  l=1,r=0;
                  f[k][i][j]=-inf;
                  continue;
               }
               if (l<=r && q[1][l]-j>y-x+1)
                  l++;
               while (l<=r && f[k-1][i][j]+j>q[0][r])
                  r--;
               q[0][++r]=f[k-1][i][j]+j;
               q[1][r]=j;
               f[k][i][j]=q[0][l]-j;
            }
         }
         break;
      case 4:
         for (int i=1;i<=n;i++)
         {
            l=1,r=0;
            for (int j=1;j<=m;j++)
            {
               if (!a[i][j])
               {
                  l=1,r=0;
                  f[k][i][j]=-inf;
                  continue;
               }
               if (l<=r && j-q[1][l]>y-x+1)
                  l++;
               while (l<=r && f[k-1][i][j]-j>q[0][r])
                  r--;
               q[0][++r]=f[k-1][i][j]-j;
               q[1][r]=j;
               f[k][i][j]=q[0][l]+j;
            }
         }
         break;
      }
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (f[p][i][j]>ans)
            ans=f[p][i][j];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
