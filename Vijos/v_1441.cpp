#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,m;
   int t[10001],x[10001],y[10001];
   long long ans;
   long long f[10001];
   scanf("%d%d",&n,&m);
   for (i=1;i<=m;i++)
      scanf("%d%d%d",&t[i],&x[i],&y[i]);
   ans=1;
   for (i=1;i<=m;i++)
      f[i]=1;
   for (i=2;i<=m;i++)
      for (j=i-1;j>=1;j--)
      {
         if (t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]) && f[i]<f[j]+1)
            f[i]=f[j]+1;
         if (f[i]>ans)
            ans=f[i];
      }
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
