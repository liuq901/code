#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
const double eps=1e-8;
struct point
{
   double x,y,z;
   point(){}
   point(double x,double y,double z):x(x),y(y),z(z){}
   double mod()
   {
      return(sqrt(SQR(x)+SQR(y)+SQR(z)));
   }
};
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
point operator *(point a,point b)
{
   return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
int main()
{
   double find(point,point,point),calc(int,point,point,point,double),work(int,point,point,point,point,int);
   bool plane(point,point,point,point);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int l,a,b,c,d,x,t;
      scanf("%d%d%d%d%d",&l,&a,&b,&c,&d);
      x=min(min(a,b),min(c,d));
      if (b==x)
         t=a,a=b,b=c,c=d,d=t;
      else if (c==x)
         swap(a,c),swap(b,d);
      else if (d==x)
         t=d,d=c,c=b,b=a,a=t;
      point A(0,0,a),B(l,0,b),C(l,l,c),D(0,l,d);
      if (!a && !b && !c && !d)
         printf("0.0000000000\n");
      else if (!a && !b || !a && !d)
         printf("ambiguous\n");
      else if (!a && !c)
         printf("error\n");
      else if (!a)
      {
         double h=find(B,C,D);
         if (h>eps)
            printf("error\n");
         else
            printf("%.10f\n",calc(l,B,C,D,h));
      }
      else if (!plane(A,B,C,D))
         printf("error\n");
      else
         printf("%.10f\n",work(l,A,B,C,D,x));
   }
   system("pause");
   return(0);
}
double find(point B,point C,point D)
{
   double dot(point,point);
   point pvec(point,point,point);
   double l=-1e8,r=1e8,p=dot(pvec(B,C,D),(point(0,0,1e8)-D));
   while (r-l>eps)
   {
      double mid=(l+r)/2;
      if (dot(pvec(B,C,D),(point(0,0,mid)-D))*p<0)
         l=mid;
      else
         r=mid;
   }
   return(r);
}
double calc(int l,point B,point C,point D,double h)
{
   double area(point,point,point,point,int);
   point A(0,0,h),a(0,0,h),b(l,0,h),c(l,l,h),d(0,l,h);
   double s=area(c,C,b,B,l),S=area(c,C,d,D,l),z=-h,x,y;
   x=z/(z+B.z)*l,y=z/(z+D.z)*l;
   return((s+S)*l/3.0-z*l*l+z*x*y/6.0);
}
double work(int l,point A,point B,point C,point D,int h)
{
   double area(point,point,point,point,int);
   point a(0,0,h),b(l,0,h),c(l,l,h),d(0,l,h);
   double s=area(c,C,b,B,l),S=area(c,C,d,D,l);
   return((s+S)*l/3.0+double(h)*l*l);
}
double area(point a,point b,point c,point d,int h)
{
   return(((a-b).mod()+(c-d).mod())*h/2.0);
}
bool plane(point A,point B,point C,point D)
{
   double dot(point,point);
   point pvec(point,point,point);
   return(fabs(dot(pvec(A,B,C),(D-A)))<eps);
}
double dot(point a,point b)
{
   return(a.x*b.x+a.y*b.y+a.z*b.z);
}
point pvec(point a,point b,point c)
{
   return((b-a)*(c-a));
}
