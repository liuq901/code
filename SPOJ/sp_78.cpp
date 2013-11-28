#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      n--,k--;
      if (n-k<k)
         k=n-k;
      long long ans=1;
      for (int i=1;i<=k;i++)
         ans=ans*(n-i+1)/i;
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
