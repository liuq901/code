#include <cstdio>
#include <cstdlib>
int main()
{
   long long gcd(long long,long long);
   long long n;
   scanf("%I64d",&n);
   n=(n+1)/2;
   printf("%I64d\n",(2*n-1)/gcd(2*n-1,n+1)/2*gcd(2*n-1,n+1)+1);
   system("pause");
   return(0);
}
long long gcd(long long a,long long b)
{
   if (b==0)
      return(a);
   else
      return(gcd(b,a%b));
}
