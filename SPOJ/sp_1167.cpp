#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      long long n;
      scanf("%lld",&n);
      long long p=(n+1)/3-1,ans=0;
      ans+=p*(p+1)/2*3+((n+1)%3+1)*(p+1);
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
