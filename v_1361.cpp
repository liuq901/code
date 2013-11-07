#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   long long n,ans;
   scanf("%I64d",&n);
   ans=(long long)(log(n)/log(3)+1);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
