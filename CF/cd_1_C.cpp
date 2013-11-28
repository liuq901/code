#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
#include <memory>
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct point
{
   double x,y;
   point(){}
   point(double _x,double _y):x(_x),y(_y){}
   double mod()
   {
      return(sqrt(SQR(x)+SQR(y)));
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
double operator *(point a,point b)
{
   return(a.x*b.x+a.y*b.y);
}
point operator *(double a,point b)
{
   return(point(a*b.x,a*b.y));
}
int main()
{
   point center(point,point,point);
   double dist(point,point);
   point A,B,C;
   scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
   point O=center(A,B,C);
   double theta[3];
   theta[0]=acos((A-O)*(B-O)/(A-O).mod()/(B-O).mod());
   theta[1]=acos((A-O)*(C-O)/(A-O).mod()/(C-O).mod());
   theta[2]=acos((B-O)*(C-O)/(B-O).mod()/(C-O).mod());
   for (int i=3;i<=100;i++)
   {
      double angle=2*pi/i;
      bool flag=true;
      for (int j=0;j<3;j++)
      {
         double p=theta[j]/angle;
         if (fabs(p-int(p+0.5))>1e-3)
         {
            flag=false;
            break;
         }
      }
      if (flag)
      {
         double len=dist(O,A);
         angle/=2;
         printf("%.10f\n",SQR(len)*sin(angle)*cos(angle)*i);
         break;
      }
   }
   system("pause");
   return(0);
}
point center(point a,point b,point c)
{
   double dist(point,point);
   double A,B,C;
   A=dist(b,c),B=dist(a,c),C=dist(a,b);
   double P,Q;
   P=(SQR(A)+SQR(B)+SQR(C))/2.0;
   Q=1.0/(1/(P-SQR(A))+1/(P-SQR(B))+1/(P-SQR(C)));
   double R=sqrt(P-Q)/2;
   double d1,d2,d3;
   d1=Q/(P-SQR(A)),d2=Q/(P-SQR(B)),d3=Q/(P-SQR(C));
   return((1-d1)/2.0*a+(1-d2)/2.0*b+(1-d3)/2.0*c);
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
