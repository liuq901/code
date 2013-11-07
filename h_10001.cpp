#include <cstdio>
#include <cstdlib>
int main()
{
   int n,a[1001],f[1001];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=n;i++)
   {
      f[i]=1;
      for (int j=1;j<=i-1;j++)
         if (a[i]>a[j] && f[j]+1>f[i])
            f[i]=f[j]+1;
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      if (f[i]>ans)
         ans=f[i];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
