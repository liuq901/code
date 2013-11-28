#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
const double eps=1e-8;
int main()
{
   void move(double,double,double,double);
   bool first=true;
   while (1)
   {
      double r,x,y,X,Y;
      scanf("%lf",&r);
      if (fabs(r+1)<eps)
         break;
      scanf("%lf%lf%lf%lf",&x,&y,&X,&Y);
      double dx=fabs(X-x),dy=fabs(Y-y);
      if (!first)
         printf("\n");
      first=false;
      if (fabs(dx)<eps || fabs(dy)<eps || fabs(dx-dy)<eps)
         move(x,y,X,Y);
      else
      {
         double d=min(dx,dy),xx,yy;
         xx=x+(X>x?d:-d),yy=y+(Y>y?d:-d);
         if (SQR(xx)+SQR(yy)<SQR(r))
            move(x,y,xx,yy),move(xx,yy,X,Y);
         else
         {
            xx=X-(X>x?d:-d),yy=Y-(Y>y?d:-d);
            move(x,y,xx,yy),move(xx,yy,X,Y);
         }
      }
   }
   system("pause");
   return(0);
}
void move(double x,double y,double X,double Y)
{
   string ans;
   if (Y-y>eps)
      ans+="north";
   if (y-Y>eps)
      ans+="south";
   if (X-x>eps)
      ans+="east";
   if (x-X>eps)
      ans+="west";
   printf("%s %.10f\n",ans.c_str(),sqrt(SQR(x-X)+SQR(y-Y)));
}
