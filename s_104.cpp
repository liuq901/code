#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,n,m,t;
   int ans[101],a[101][101],f[101][101];
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
         scanf("%d",&a[i][j]);
         a[i][j]+=100;
      }
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      for (j=i;j<=m;j++)
      {
         if (f[i-1][j-1]+a[i][j]>f[i][j])
            f[i][j]=f[i-1][j-1]+a[i][j];
         if (f[i][j-1]>f[i][j])
            f[i][j]=f[i][j-1];
      }
   t=m;
   for (i=n;i>=1;i--)
   {
      while (1)
      {
         if (f[i][t]!=f[i][t-1])
         {
            ans[i]=t;
            t--;
            break;
         }
         t--;
      }
   }
   printf("%d\n",f[n][m]-n*100);
   for (i=1;i<=n;i++)
   {
      printf("%d",ans[i]);
      if (i==n)
         printf("\n");
      else
         printf(" ");
   }
   system("pause");
   return(0);
}
