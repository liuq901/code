#include <cstdio>
#include <cstdlib>
int main()
{
   long long a,b;
   scanf("%lld%lld",&a,&b);
   if (!(a&1))
      a--;
   if (!(b&1))
      b++;
   printf("%lld\n",b-a>>1);
   system("pause");
   return(0);
}
