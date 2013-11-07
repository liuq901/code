#include <cstdio>
#include <cstdlib>
int main()
{
   int m,n,x,i,j,k,t,a[600],b[600],f[600]={0},max;
   scanf("%d",&x);
   for (t=1;t<=x;t++)
   {
      for (i=0;i<600;i++)
         f[i]=0;
      scanf("%d",&n);
      for (i=1;i<=n;i++)
         scanf("%d",&a[i]);
      scanf("%d",&m);
      for (i=1;i<=m;i++)
         scanf("%d",&b[i]);
      a[n+1]=b[m+1]=2147483647;
      for (i=1;i<=n+1;i++)
      {
         k=0;
         for (j=1;j<=m+1;j++)
            if (a[i]==b[j])
               f[j]=k+1;
            else
               if (a[i]>b[j])
                  k=(k>f[j])?k:f[j];
      }
      printf("%d\n",f[m+1]-1);
   }
   system("pause");
   return(0);
}
