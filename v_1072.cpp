#include <cstdio>
#include <cstdlib>
int main()
{
   double s,l,t,v;
   scanf("%lf",&l);
   scanf("%lf",&v);
   t=(2*l)/(3*v);
   s=v*t;
   printf("%.1lf\n",s);
   printf("%.1lf\n",t);
   system("pause");
   return(0);
}
