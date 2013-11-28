#include <cstdio>
#include <cstdlib>
int main()
{
   long long ans=0;
   for (int i=1;i<1000;i++)
      if (!(i%3) || !(i%5))
         ans+=i;
   printf("%lld\n",ans);
   system("pause");
   return(0);
}
