#include <cstdio>
#include <cstdlib>
#include <cmath>
#define SQR(x) ((x)*(x))
const double eps=1e-8;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      double x1,y1,x,y;
      scanf("%lf%lf",&x1,&y1);
      if (fabs(x1)<eps && fabs(y1)<eps)
         x=0,y=0;
      else
      {
         double l=x1,r=1e10;
         for (int i=1;i<=100;i++)
         {
            double mid=(l+r)/2;
            if (y1+sqrt(mid)>SQR(mid-x1))
               l=mid;
            else
               r=mid;
         }
         x=(l+r)/2,y=SQR(x-x1);
      }
      static int id=0;
      printf("Case %d: %.6f %.6f\n",++id,x,y);
   }
   system("pause");
   return(0);
}
