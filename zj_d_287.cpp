#include <cstdio>
#include <cstdlib>
typedef long long int64;
int main()
{
   int64 gcd(int64,int64);
   int64 a,b;
   while (scanf("%lld%lld",&a,&b)!=EOF)
      printf("%lld\n",a==b?a:(a+b)/gcd(a,b)-1);
   system("pause");
   return(0);
}
int64 gcd(int64 a,int64 b)
{
   return(b?gcd(b,a%b):a);
}
