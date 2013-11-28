#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,k,n,m;
   int a[101];
   long long ans;
   long long f[101][101];
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      f[i][1]=1;
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
         for (k=1;k<=i-1;k++)
            if (a[i]>=a[k])
               f[i][j]+=f[k][j-1];
   ans=0;
   for (i=1;i<=n;i++)
      ans+=f[i][m];
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
