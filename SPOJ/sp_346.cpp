#include <cstdio>
#include <cstdlib>
#include <cstring>
long long f[10000001];
int main()
{
   long long get(int);
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%lld\n",get(n));
   system("pause");
   return(0);
}
long long get(int x)
{
   long long max(long long,long long);
   if (x<=10000000 && f[x])
      return(f[x]);
   if (x<=1)
      return(x);
   long long ans=max(get(x/2)+get(x/3)+get(x/4),x);
   if (x<=10000000)
      f[x]=ans;
   return(ans);
}
long long max(long long x,long long y)
{
   return(x>y?x:y);
}
