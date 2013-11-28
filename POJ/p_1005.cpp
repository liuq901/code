#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535897;
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      double x,y;
      scanf("%lf%lf",&x,&y);
      double area=pi*(x*x+y*y)/2;
      printf("Property %d: This property will begin eroding in year %.0lf.\n",i,ceil(area/50));
   }
   printf("END OF OUTPUT.\n");
   system("pause");
   return(0);
}
