#include <cstdio>
#include <cstdlib>
int main()
{
   int max(int,int,int);
   int s,n,i,j;
   int h[101],f[101][2001];
   scanf("%d",&n);
   s=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&h[i]);
      s+=h[i];
   }
   for (i=0;i<=n;i++)
      for (j=0;j<=s;j++)
         f[i][j]=-2000000;
   f[0][0]=0;
   for (i=1;i<=n;i++)
      for (j=s/2;j>=0;j--)
         if (j>=h[i])
            f[i][j]=max(f[i-1][j],f[i-1][j+h[i]],f[i-1][j-h[i]]+h[i]);
         else
            f[i][j]=max(f[i-1][j],f[i-1][j+h[i]],f[i-1][h[i]-j]+j);
   if (f[n][0]==0)
      printf("Impossible\n");
   else
      printf("%d\n",f[n][0]);
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
