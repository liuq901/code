#include <cstdio>
#include <cstdlib>
int main()
{
   long long a,b;
   while (scanf("%lld%lld",&a,&b)!=EOF)
   {
      a-=b;
      if (a<0)
         a=-a;
      printf("%lld\n",a);
   }
   system("pause");
   return(0);
}
