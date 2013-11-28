#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   double x,y;
   while (scanf("%lf%lf",&x,&y)==2)
      printf("%.3f\n",pow(x,y));
   system("pause");
   return(0);
}
