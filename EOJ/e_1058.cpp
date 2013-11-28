#include <cstdio>
#include <cstdlib>
#include <cmath>
double x[100010],y[100010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n<3)
         break;
      for (int i=1;i<=n;i++)
         scanf("%lf%lf",&x[i],&y[i]);
      x[0]=x[n],y[0]=y[n];
      double sum=0;
      for (int i=1;i<=n;i++)
         sum+=x[i]*y[i-1]-y[i]*x[i-1];
      sum=fabs(sum)/2;
      double x;
      scanf("%lf",&x);
      printf("BAR LENGTH: %.2f\n",x/sum);
   }
   system("pause");
   return(0);
}
