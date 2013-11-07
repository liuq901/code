#include <cstdio>
#include <cstdlib>
int main()
{
   double t1,t2,t3,x1,x3;
   while (scanf("%lf%lf%lf%lf%lf",&t1,&t2,&t3,&x1,&x3)==5)
      printf("%f\n",x1+(t2-t1)/(t3-t1)*(x3-x1));
   system("pause");
   return(0);
}
