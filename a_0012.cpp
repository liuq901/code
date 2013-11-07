#include <cstdio>
#include <cstdlib>
#include <cmath>
struct point
{
   double x,y;
   point(){}
   point(double x,double y):x(x),y(y){}
};
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y));
}
double operator *(point a,point b)
{
   return(a.x*b.y-b.x*a.y);
}
int main()
{
   point P,a[10];
   while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a[1].x,&a[1].y,&a[2].x,&a[2].y,&a[3].x,&a[3].y,&P.x,&P.y)==8)
   {
      double area=0,sum=0;
      a[4]=a[1];
      for (int i=1;i<=3;i++)
      {
         area+=(a[i]-P)*(a[i+1]-P);
         sum+=fabs((a[i]-P)*(a[i+1]-P));
      }
      printf("%s\n",fabs(fabs(area)-sum)<1e-7?"YES":"NO");
   }
   system("pause");
   return(0);
}
