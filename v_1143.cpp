#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[61][31][31][31];
int main()
{
   int min(int,int);
   int n,i,j,k,t;
   int a[31][31];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   memset(f,0,sizeof(f));
   for (t=2;t<=2*n;t++)
      for (i=1;i<=min(n,t-1);i++)
         for (j=1;j<=min(n,t-1);j++)
            for (k=1;k<=min(n,t-1);k++)
            {
               if (f[t-1][i][j][k]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i][j][k];
               if (f[t-1][i-1][j][k]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i-1][j][k];
               if (f[t-1][i][j-1][k]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i][j-1][k];
               if (f[t-1][i][j][k-1]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i][j][k-1];
               if (f[t-1][i-1][j-1][k]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i-1][j-1][k];
               if (f[t-1][i-1][j][k-1]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i-1][j][k-1];
               if (f[t-1][i][j-1][k-1]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i][j-1][k-1];
               if (f[t-1][i-1][j-1][k-1]>f[t][i][j][k])
                  f[t][i][j][k]=f[t-1][i-1][j-1][k-1];
               if (i==j && j==k)
                  f[t][i][j][k]+=a[i][t-i];
               else if (i==j)
                  f[t][i][j][k]+=a[i][t-i]+a[k][t-k];
               else if (i==k || j==k)
                  f[t][i][j][k]+=a[i][t-i]+a[j][t-j];
               else
                  f[t][i][j][k]+=a[i][t-i]+a[j][t-j]+a[k][t-k];
            }
   printf("%d\n",f[2*n][n][n][n]);
   system("pause");
   return(0);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
