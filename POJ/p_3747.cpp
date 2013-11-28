#include <cstdio>
#include <cstdlib>
#include <cmath>
#define SQR(x) ((x)*(x))
const double eps=1e-7;
const double pi=acos(-1.0);
const int m=12;
struct point
{
   double x,y;
   point(){}
   point(double x,double y):x(x),y(y){};
};
point operator +(point a,point b)
{
   return(point(a.x+b.x,a.y+b.y));
}
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y));
}
point operator *(point a,double b)
{
   return(point(a.x*b,a.y*b));
}
double operator *(point a,point b)
{
   return(a.x*b.x+a.y*b.y);
}
point a[20];
int n;
int main()
{
   point rotate(point,double);
   bool check(point);
   int r;
   while (scanf("%d%d",&n,&r)==2)
   {
      for (int i=0;i<=n;i++)
         scanf("%lf%lf",&a[i].x,&a[i].y);
      point now(0,r);
      bool flag=false;
      for (int i=1;i<=m;i++)
      {
         now=rotate(now,2*pi/m);
         if (check(now))
         {
            flag=true;
            break;
         }
      }
      printf("%s\n",flag?"Yes":"No");
   }
   system("pause");
   return(0);
}
point rotate(point p,double x)
{
   return(point(p.x*cos(x)-p.y*sin(x),p.x*sin(x)+p.y*cos(x)));
}
bool check(point p)
{
   double dist(point,point);
   for (int i=1;i<=n;i++)
   {
      double rate=(a[i]-a[0])*(p-a[0])/SQR(p-a[0]);
      point P=a[0]+(p-a[0])*rate;
      if (dist(a[i],p)<=dist(a[0],p)+eps)
         return(false);
   }
   return(true);
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
