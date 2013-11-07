#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,k,n;
   int f[22][11];
   long long ans;
   scanf("%d",&n);
   memset(f,0,sizeof(f));
   for (i=0;i<=10;i++)
      f[1][i]=f[n+1][i]=1;
   for (i=2;i<=n;i++)
      for (j=1;j<=10;j++)
         f[i][j]=f[i-1][j]+f[i][j-1];
   ans=0;
   for (i=1;i<=n;i++)
      for (j=i;j<=n;j++)
         for (k=1;k<=10;k++)
            ans+=(long long)f[i][k-1]*f[n-j+1][k-1];
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
