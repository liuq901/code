#include <cstdio>
#include <cstdlib>
#include <cmath>
double eps=1e-8;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      double a,b,c,d;
      scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
      if (fabs(b)>eps || fabs(d)>eps)
         printf("No\n");
      else
         printf("%c\n",a>c?'>':a==c?'=':'<');
   }
   system("pause");
   return(0);
}
