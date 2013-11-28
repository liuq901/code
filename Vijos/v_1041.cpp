#include <cstdio>
#include <cstdlib>
int main()
{
   double p,q;
   int i;
   scanf("%lf%lf",&p,&q);
   i=0;
   while (1)
   {
      i++;
      if ((int)(i*p/100.0+0.00001)<(int)(i*q/100.0-0.00001))
         break;
   }
   printf("%d\n",i);
   system("pause");
   return(0);
}
