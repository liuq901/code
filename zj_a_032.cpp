#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i;
   long long ans;
   while (scanf("%d",&n)!=EOF)
   {
      ans=1;
      for (i=1;i<=n;i++)
         ans*=i;
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
