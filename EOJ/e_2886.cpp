#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   double x,y;
   scanf("%lf",&x);
   if (x<=1500)
      y=0;
   else if (x<=3000)
      y=0.05;
   else if (x<=5000)
      y=0.1;
   else if (x<=10000)
      y=0.15;
   else
      y=0.2;
   printf("%.2f\n",max(0.0,x-1500)*y);
   system("pause");
   return(0);
}
