#include <cstdio>
#include <cstdlib>
int main()
{
   long long min(long long,long long);    
   long long n,m;
   scanf("%I64d%I64d",&n,&m);
   printf("%I64d\n",min((n<<1)-2,(m<<1)-1));
   system("pause");
   return(0);
}
long long min(long long x,long long y)
{
   return(x<y?x:y);
}
