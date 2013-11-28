#include <cstdio>
#include <cstdlib>
#include <math.h>
double tl=0;
int main()
{
   void line(double,double,double,double);
   int i,n;
   double r,x,y,xx,yy,xxx,yyy;
   scanf("%d%lf",&n,&r);
   if (n==1)
   {
      printf("%.2lf\n",2*3.1415926*r);
      system("pause");
      exit(0);
   }
   scanf("%lf%lf",&x,&y);
   xxx=x;
   yyy=y;
   for (i=1;i<=n-1;i++)
   {
      scanf("%lf%lf",&xx,&yy);
      line(x,y,xx,yy);
      x=xx;
      y=yy;
   }
   line(xx,yy,xxx,yyy);
   printf("%.2lf\n",(double)(tl+2*3.1415926*r));
   system("pause");
   return(0);
}
void line(double x1,double y1,double x2,double y2)
{
   double sqr(double);
   if (x1==x2)
      tl+=fabs(y1-y2);
   if (y1==y2)
      tl+=fabs(x1-x2);
   if (x1!=x2 && y1!=y2)
      tl+=sqrt(sqr(fabs(x1-x2))+sqr(fabs(y1-y2)));
}
double sqr(double x)
{
   return(x*x);
}
