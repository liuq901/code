#include <cstdio>
#include <cstdlib>
#include <cmath>
const double eps=1e-12;
int main()
{
   while (1)
   {
      long long x;
      scanf("%I64d",&x);
      if (!x)
         break;
      bool flag=true;
      if (x<0)
      {
         flag=false;
         x=-x;
      }
      for (int i=32;i>=1;i--)
      {
         if (!flag && !(i&1))
            continue;
         double p=pow(x,1.0/i);
         if (fabs(p-(long long)p)<eps || fabs(p-ceil(p))<eps)
         {
            printf("%d\n",i);
            break;
         }
      }
   }
   system("pause");
   return(0);
}
