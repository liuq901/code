#include <cstdio>
#include <cstdlib>
const double pi=3.1415927;
int main()
{
   while (1)
   {
      double d,t;
      int n;
      scanf("%lf%d%lf",&d,&n,&t);
      if (!n)
         break;
      double len=n*d*pi/12/5280;
      static int id=0;
      printf("Trip #%d: %.2f %.2f\n",++id,len,len/t*3600);
   }
   system("pause");
   return(0);
}
