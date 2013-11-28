#include <cstdio>
#include <cstdlib>
const int mod=10007;
int main()
{
   int calc(int,int);
   int a,b;
   scanf("%d%d",&a,&b);
   printf("%d\n",calc(a%mod,b));
   system("pause");
   return(0);
}
int calc(int x,int n)
{
   if (!n)
      return(1);
   long long ret=calc(x,n>>1);
   ret*=ret;
   if (n&1)
      ret*=x;
   return(ret%mod);
}
