#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535897;
int main()
{
   int n;
   double r;
   scanf("%d%lf",&n,&r);
   double x0,y0,sum=2*pi*r;
   scanf("%lf%lf",&x0,&y0);
   double x=x0,y=y0;
   for (int i=2;i<=n;i++)
   {
      double p,q;
      scanf("%lf%lf",&p,&q);
      sum+=sqrt((p-x)*(p-x)+(q-y)*(q-y));
      x=p,y=q;
   }
   sum+=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
   printf("%.2lf\n",sum);
   system("pause");
}
