#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double x;
   long long n,ans;
   scanf("%I64d",&n);
   x=(sqrt(5)-1)/2;
   ans=(long long)((n+1)*x);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
