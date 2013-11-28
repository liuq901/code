#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int m,n,i,j,k,x,y;
   int a[301],b[301],f[301][301];
   scanf("%d%d",&m,&n);
   a[0]=b[0]=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&x,&y);
      a[i]=a[i-1]+x;
      b[i]=b[i-1]+y;
   }
   memset(f,26,sizeof(f));
   for (i=1;i<=n;i++)
      if (a[i]<=m)
         f[i][i]=2;
   for (i=1;i<=n;i++)
      for (j=i;j>=0;j--)
         for (k=0;k<=i-j;k++)
            if (f[i-j][k]+1<f[i][j] && a[i]+b[i-j]-a[i-j]-b[i-j-k]<=m)
               f[i][j]=f[i-j][k]+1;
   printf("%d\n",f[n][0]);
   system("pause");
   return(0);
}
