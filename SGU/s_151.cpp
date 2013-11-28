#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double b,c,m,x,y;
   scanf("%lf%lf%lf",&c,&b,&m);
   if (2*m<fabs(b-c) || 2*m>b+c)
      printf("Mission impossible\n");
   else
   {
      x=(4*m*m-c*c-b*b)/c/2.0;
      if (b*b-x*x>=0)
         y=sqrt(b*b-x*x);
      else
         y=0;
      printf("0 0\n");
      printf("%lf 0\n",c);
      printf("%lf %lf\n",x,y);
   }
   system("pause");
   return(0);
}
