#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
int main()
{
   while (1)
   {
      double a,b,x,y;
      scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
      if (!a && !b && !x && !y)
         break;
      if (a<b)
         swap(a,b);
      if (x<y)
         swap(x,y);
      if (a>x && b>y)
         printf("Escape is possible.\n");
      else if (y>=b || x*y>=a*b || SQR(x)+SQR(y)>SQR(a)+SQR(b))
         printf("Box cannot be dropped.\n");
      else
      {
         double n=SQR(x)+SQR(y);
         if (SQR((a-sqrt(n-SQR(b)))/2.0)+SQR((b-sqrt(n-SQR(a)))/2.0)>SQR(y))
            printf("Escape is possible.\n");
         else
            printf("Box cannot be dropped.\n");
      }
   }
   system("pause");
   return(0);
}
