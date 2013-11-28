#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,i,j,k,l,max;
   int a[201],b[201],f[201][201];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=n-1;i++)
      b[i]=a[i+1];
   b[n]=a[1];
   m=2*n-1;
   for (i=n+1;i<=m;i++)
   {
      a[i]=a[i-n];
      b[i]=b[i-n];
   }
   memset(f,0,sizeof(f));
   for (i=1;i<=n-1;i++)
      for (j=1;j<=m-1;j++)
      {
         k=j+i;
         if (k>m)
            break;
         for (l=j;l<=k-1;l++)
            if (f[j][k]<f[j][l]+f[l+1][k]+a[j]*b[l]*b[k])
               f[j][k]=f[j][l]+f[l+1][k]+a[j]*b[l]*b[k];
      }
   max=0;
   for (i=1;i<=n;i++)
      if (max<f[i][i+n-1])
         max=f[i][i+n-1];
   printf("%d\n",max);
   system("pause");
   return(0);
}
