#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double m,n,r,min;
   scanf("%lf%lf%lf",&m,&n,&r);
   if (n>=m)
      min=r;
   else 
      min=sqrt(r*r+(m-n)*(m-n));
   printf("%.3lf\n",min);
   system("pause");
   return(0);
}
