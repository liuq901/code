#include <cstdio>
#include <cstdlib>
#define T(x) ((x)*((x)+1)/2)
#define P(x) ((x)*(3*(x)-1)/2)
#define H(x) ((x)*(2*(x)-1))
int main()
{
   long long t=286,p=166,h=144;
   while (1)
   {
      if (T(t)==P(p) && T(t)==H(h))
      {
         printf("%lld\n",T(t));
         break;
      }
      if (T(t)<=P(p) && T(t)<=H(h))
         t++;
      else if (P(p)<=H(h))
         p++;
      else
         h++;
   }
   system("pause");
   return(0);
}
