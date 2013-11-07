#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double a,b,c,delta,x1,x2,t;
   while (scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
   {
      delta=b*b-4*a*c;
      if (delta<0)
      {
         printf("No real root\n");
         continue;
      }
      x1=(-b+sqrt(delta))/(2*a);
      x2=(-b-sqrt(delta))/(2*a);
      if (x1<x2)
         t=x1,x1=x2,x2=t;
      if (delta==0)
         printf("Two same roots x=%.0lf\n",x1);
      else
         printf("Two different roots x1=%.0lf , x2=%.0lf\n",x1,x2);
   }
   system("pause");
   return(0);
}
