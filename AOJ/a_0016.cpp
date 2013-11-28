#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
   double x0,y0,angle;
   x0=y0=0;
   angle=pi/2;
   while (1)
   {
      int x,y;
      scanf("%d,%d",&x,&y);
      if (!x && !y)
         break;
      x0+=x*cos(angle),y0+=x*sin(angle);
      angle-=pi*y/180.0;
   }
   printf("%d\n%d\n",int(x0),int(y0));
   system("pause");
   return(0);
}
