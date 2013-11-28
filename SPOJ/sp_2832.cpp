#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,j,k;
   long long p,t,ans;
   long long a[201][201];
   while (scanf("%d%lld",&n,&p)!=EOF)
   {
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
         {
            scanf("%lld",&a[i][j]);
            a[i][j]%=p;
         }
      ans=1;
      for (i=1;i<=n;i++)
      {
         for (j=i+1;j<=n;j++)
            while (a[j][i]!=0)
            {
               t=a[i][i]/a[j][i];
               for (k=1;k<=n;k++)
               {
                  a[i][k]-=a[j][k]*t;
                  a[i][k]%=p;
               }
               for (k=1;k<=n;k++)
                  t=a[i][k],a[i][k]=a[j][k],a[j][k]=t;
               ans*=-1;
            }
         ans*=a[i][i];
         ans%=p;
      }
      while (ans<0)
         ans+=p;
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
