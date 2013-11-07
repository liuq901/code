#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,i,j,k,p,best;
   int top[201],wei[201];
   int f[201][201]={0};
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&top[i]);
   for (i=1;i<n;i++)
      wei[i]=top[i+1];
   wei[n]=top[1];
   m=n*2-1;
   for (i=n+1;i<=m;i++)
   {
      top[i]=top[i-n];
      wei[i]=wei[i-n];
   }
   for (p=1;p<=n-1;p++)
      for (i=1;i<=m+1;i++)
      {
         j=i+p;
         if (j>m)
            break;
         for (k=i;k<=j-1;k++)
            if (f[i][j]<f[i][k]+f[k+1][j]+top[i]*wei[k]*wei[j])
               f[i][j]=f[i][k]+f[k+1][j]+top[i]*wei[k]*wei[j];
      }
   best=0;
   for (i=1;i<=n;i++)
      if (best<f[i][i+n-1])
         best=f[i][i+n-1];
   printf("%d\n",best);
   system("pause");
   return(0);
}
