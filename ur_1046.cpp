#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535897;
int main()
{
   int n;
   scanf("%d",&n);
   double x[55],y[55],angle[55];
   for (int i=1;i<=n;i++)
      scanf("%lf%lf",&x[i],&y[i]);
   for (int i=1;i<=n;i++)
   {
      scanf("%lf",&angle[i]);
      angle[i]=angle[i]/180*pi;
   }
   x[n+1]=x[1];
   y[n+1]=y[1];
   angle[n+1]=angle[1];
   double a1,a2,a3,b1,b2,b3;
   a1=b2=1;
   a2=a3=b1=b3=0;
   for (int i=1;i<=n;i++)
   {
      double c,d,a,b,aa1,aa2,aa3,bb1,bb2,bb3;
      c=cos(angle[i]),d=sin(angle[i]);
      a=a1+a2+a3,b=b1+b2+b3;
      aa1=a1*c-b1*d;
      aa2=a2*c-b2*d;
      aa3=a3*c-b3*d+x[i]-x[i+1];
      bb1=b1*c+a1*d;
      bb2=b2*c+a2*d;
      bb3=b3*c+a3*d+y[i]-y[i+1];
      a1=aa1,a2=aa2,a3=aa3;
      b1=bb1,b2=bb2,b3=bb3;
   }
   double x1=a1-1,y1=a2,z1=-a3,x2=b1,y2=b2-1,z2=-b3;
   b2=(z1*x2-z2*x1)/(y1*x2-y2*x1);
   a1=(z1*y2-z2*y1)/(x1*y2-x2*y1);
   a2=a3=b1=b3=0;
   for (int i=1;i<=n;i++)
   {
      double c,d,a,b,aa1,aa2,aa3,bb1,bb2,bb3;
      c=cos(angle[i]),d=sin(angle[i]);
      a=a1+a2+a3,b=b1+b2+b3;
      printf("%lf %lf\n",a+x[i],b+y[i]);
      aa1=a1*c-b1*d;
      aa2=a2*c-b2*d;
      aa3=a3*c-b3*d+x[i]-x[i+1];
      bb1=b1*c+a1*d;
      bb2=b2*c+a2*d;
      bb3=b3*c+a3*d+y[i]-y[i+1];
      a1=aa1,a2=aa2,a3=aa3;
      b1=bb1,b2=bb2,b3=bb3;
   }
   system("pause");
   return(0);
}
