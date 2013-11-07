#include <cstdio>
#include <cstdlib>
const int inf=1<<30;
int f[2001][2001],g[2001][2001],h[2001][2001];
int main()
{
   int min(int,int);
   int n,m,a[2001],b[2001];
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      a[i]--;
   }
   for (int i=1;i<=m;i++)
   {
      scanf("%d",&b[i]);
      b[i]--;
   }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (i==1 && j==1)
         {
            f[i][j]=g[i][j]=h[i][j]=a[i]*b[j];
            continue;
         }
         if (i==1 || j==1)
         {
            g[i][j]=h[i][j]=inf;
            if (i>1)
               g[i][j]=g[i-1][j]+a[i]*b[j];
            else
               h[i][j]=h[i][j-1]+a[i]*b[j];
         }
         else
         {
            g[i][j]=min(f[i-1][j-1],g[i-1][j])+a[i]*b[j];
            h[i][j]=min(f[i-1][j-1],h[i][j-1])+a[i]*b[j];
         }
         f[i][j]=min(g[i][j],h[i][j]);
      }
   printf("%d\n",f[n][m]);
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
