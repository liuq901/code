#include <cstdio>
#include <cstdlib>
int main()
{
   int n,k,m;
   scanf("%d%d%d",&n,&k,&m);
   long long ans=1;
   for (int i=1;i<=k;i++)
      ans=ans*(n-i+1)/i;
   ans*=ans;
   for (int i=1;i<=k;i++)
      ans*=i*i;
   for (int i=1;i<=m;i++)
   {
      int x;
      scanf("%d",&x);
      for (int j=1;j<=x;j++)
         ans/=j;
   }
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
