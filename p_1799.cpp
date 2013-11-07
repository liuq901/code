#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535897;
int main()
{
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      double r;
      int n;
      scanf("%lf%d",&r,&n);
      printf("Scenario #%d:\n%.3lf\n\n",id,r/(1+1/sin(pi/n)));
   }
   system("pause");
   return(0);
}
