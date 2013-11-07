#include <cstdio>
#include <cstdlib>
#include <cmath>
#define SQR(x) ((x)*(x))
struct point
{
   double x,y;
   point(){}
   point(double x,double y):x(x),y(y){}
};
int main()
{
   point center(point,point,point);
   double dist(point,point);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      point A,B,C;
      scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
      point P=center(A,B,C);
      printf("%.3f %.3f %.3f\n",P.x,P.y,dist(A,P));
   }
   system("pause");
   return(0);
}
point center(point p0,point p1,point p2)
{
   double a1=p1.x-p0.x,b1=p1.y-p0.y,c1=(SQR(a1)+SQR(b1))/2;
   double a2=p2.x-p0.x,b2=p2.y-p0.y,c2=(SQR(a2)+SQR(b2))/2;
   double d=a1*b2-a2*b1;
   return(point(p0.x+(c1*b2-c2*b1)/d,p0.y+(a1*c2-a2*c1)/d));
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
