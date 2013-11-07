#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,n,k,x;
   long long ans,s;
   long long a[100001];
   memset(a,0,sizeof(a));
   s=0;
   scanf("%d%d",&n,&k);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      s+=x;
      a[s%k]++;
   }
   ans=0;
   for (i=0;i<=k;i++)
   {
      if (a[i]*(a[i]-1)>0)
         ans+=a[i]*(a[i]-1)/2;
      ans%=1234567;
   }
   printf("%I64d\n",(ans+a[0])%1234567);
   system("pause");
   return(0);
}
