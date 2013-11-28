#include <cstdio>
#include <cstdlib>
int main()
{
   long long a,b,c;
   while (scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
      printf("%lld\n",a+b+c);
   system("pause");
   return(0);
}
