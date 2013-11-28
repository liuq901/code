#include <cstdio>
#include <cstdlib>
#include <cmath>
const double g=9.8;
int main()
{
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      double s=(n-1)*3;
      if (n>=3)
         s+=4;
      else if (n==2)
         s+=2;
      s+=1.75;
      printf("%.3lf\n",sqrt(2*s/g));
   }
   system("pause");
   return(0);
}
