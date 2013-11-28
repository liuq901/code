#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int min(int,int);
   int max(int,int,int,int);
   int i,j,k,n,m;
   int a[51][51],f[101][51][51];
   scanf("%d%d",&m,&n);
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   memset(f,0,sizeof(f));
   f[1][1][2]=a[1][2]+a[2][1];
   for (i=2;i<=m;i++)
      f[i][i][i+1]=f[i-1][i-1][i]+a[i][2]+a[i+1][1];
   for (i=2;i<=n;i++)
      f[i][1][2]=f[i-1][1][2]+a[1][i+1]+a[2][i];
   for (i=2;i<=n+m-2;i++)
      for (j=1;j<=min(i,m-1);j++)
         for (k=j+1;k<=min(i+1,m);k++)
            if (k==j+1)
               f[i][j][k]=max(f[i-1][j-1][k-1],f[i-1][j-1][k],f[i-1][j][k],0)+a[j][i-j+2]+a[k][i-k+2];
            else
               f[i][j][k]=max(f[i-1][j-1][k-1],f[i-1][j-1][k],f[i-1][j][k],f[i-1][j][k-1])+a[j][i-j+2]+a[k][i-k+2];
   printf("%d\n",f[n+m-3][m-1][m]);
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
int max(int a,int b,int c,int d)
{
   int x;
   x=a;
   if (b>x)
      x=b;
   if (c>x)
      x=c;
   if (d>x)
      x=d;
   return(x);
}
