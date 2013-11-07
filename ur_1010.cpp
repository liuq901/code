#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int n,p;
   double m,max;
   scanf("%d%lf",&n,&m);
   max=0,p=2;
   for (int i=2;i<=n;i++)
   {
      double t=m;
      scanf("%lf",&m);
      if (fabs(t-m)>max)
      {
         max=fabs(t-m);
         p=i;
      }
   }
   printf("%d %d\n",p-1,p);
   system("pause");
   return(0);
}
