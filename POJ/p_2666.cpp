#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=acos(-1.0);
int main()
{
   while (1)
   {
      int u,a,d;
      scanf("%d%d%d",&u,&a,&d);
      if (!u && !a && !d)
         break;
      double ans=(exp((a/180.0*pi+sqrt(3.0)*log(double(d)))/sqrt(3.0))-d)/u;
      if (ans>10000.5)
         printf("God help me!\n");
      else
         printf("%.0f\n",ans);
   }
   system("pause");
   return(0);
}
