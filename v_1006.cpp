#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1002][1002];
int b[1002][1002];
int main()
{
   int min(int,int);
   int n,i,j;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=i;j++)
      scanf("%d",&a[i][j]);
   }
   for (i=1;i<=n;i++)
   {
      a[i][0]=a[i][i];
      a[i][i+1]=a[i][1];
   }
   memset(b,0,sizeof(int)*1002*1002);
   for (i=1;i<=n;i++)
      b[n][i]=b[n][i-1]+a[n][i];
   b[n][n]=a[n][1]+a[n][n];
   for (i=n-1;i>=2;i--)
      if (b[n][i]>b[n][i+1]+a[n][i])
   b[n][i]=b[n][i+1]+a[n][i];
   for (i=n-1;i>=1;i--)
   {
      for (j=1;j<=i;j++)
         if (j==1)
            b[i][j]=min(b[i+1][i+1],min(b[i+1][j],b[i+1][j+1]))+a[i][j];
         else if (j!=1&&j!=i)
            b[i][j]=min(b[i][j-1],min(b[i+1][j],b[i+1][j+1]))+a[i][j];
         else if (j==i)
            b[i][j]=min(b[i][j-1],min(b[i+1][1],min(b[i+1][j],b[i+1][j+1])))+a[i][j];
      for (j=1;j<=i;j++)
         if (j==1)
            b[i][j]=min(b[i][j],b[i][i]+a[i][j]);
         else
            b[i][j]=min(b[i][j],b[i][j-1]+a[i][j]);
      for (j=i;j>=1;j--)
         if (j==i)
            b[i][j]=min(b[i][j],b[i][1]+a[i][j]);
         else
            b[i][j]=min(b[i][j],b[i][j+1]+a[i][j]);
   }
   printf("%d\n",b[1][1]);
   system("pause");
   return(0);
}
int min(int a,int b)
{
   if (a<b)
      return(a);
   else
      return(b);
}
