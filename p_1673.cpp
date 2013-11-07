#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
const double eps=1e-8;
struct point
{
   double x,y;
   point(){}
   point(double x,double y):x(x),y(y){}
   point rotate()
   {
      return(point(-y,x));
   }
   point unit()
   {
      double mod=sqrt(SQR(x)+SQR(y));
      return(point(x/mod,y/mod));
   }
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
   return(a.x*b.y-a.y*b.x);
}
int main()
{
   point work(point,point,point);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      double x1,y1,x2,y2,x3,y3;
      scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
      point ans=work(point(x1,y1),point(x2,y2),point(x3,y3));
      printf("%.4f %.4f\n",ans.x,ans.y);
   }
   system("pause");
   return(0);
}
point work(point A,point B,point C)
{
   double dist(point,point);
   point mid(point,point),intersection(point,point,point,point);
   if ((B-A)*(C-B)>eps)
      swap(B,C);
   point D,E,G,J;
   D=A+(B-A).rotate().unit()*dist(A,B);
   E=B+(B-A).rotate().unit()*dist(A,B);
   G=A+(A-C).rotate().unit()*dist(A,C);
   J=B+(C-B).rotate().unit()*dist(B,C);
   point L,M;
   L=mid(D,G),M=mid(E,J);
   point O;
   O=intersection(A,L,B,M);
   return(O);
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
point mid(point a,point b)
{
   return((a+b)*0.5);
}
point intersection(point u1,point u2,point v1,point v2)
{
   double t=(u1-v1)*(v1-v2)/((u1-u2)*(v1-v2));
   return(u1+(u2-u1)*t);
}
