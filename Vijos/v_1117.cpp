#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int f[201][7];
   int i,j,n,m;
   scanf("%d%d",&n,&m);
   memset(f,0,sizeof(f));
   f[0][0]=1;
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         if (i>=j)
            f[i][j]=f[i-1][j-1]+f[i-j][j];
         else
            f[i][j]=f[i-1][j-1];
   printf("%d\n",f[n][m]);
   system("pause");
   return(0);
}
