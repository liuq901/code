#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,i,j;
   int f[31][31];
   scanf("%d%d",&n,&m);
   memset(f,0,sizeof(f));
   f[0][1]=1;
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
      {
         if (j==1)
            f[i][j]=f[i-1][n]+f[i-1][j+1];
         if (j==n)
            f[i][j]=f[i-1][j-1]+f[i-1][1];
         if (j>1 && j<n)
            f[i][j]=f[i-1][j-1]+f[i-1][j+1];
      }
   printf("%d\n",f[m][1]);
   system("pause");
   return(0);
}
