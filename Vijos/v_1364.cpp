#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[2600][2600],f[2600][2600];
int main()
{
   int max(int,int,int);
   int m,n,i,j;
   scanf("%d%d",&m,&n);
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   memset(f,0,sizeof(f));
   for (i=1;i<=m+1;i++)
      for (j=1;j<=n;j++)
         f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j],f[i-1][j+1]+a[i][j]);
   printf("%d\n",f[m+1][n/2+1]);
   system("pause");
   return(0);
}
int max(int x,int y,int z)
{
   if (x>y)
      if (x>z)
         return(x);
      else
         return(z);
   else
      if (y>z)
         return(y);
      else
         return(z);
}
