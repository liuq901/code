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
point operator *(point a,double b)
{
   return(point(a.x*b,a.y*b));
}
point a[160];
int main()
{
   double dist(point,point);
   point solve(double,int,int,int),rotate(point,double);
   int n,n1,n2;
   scanf("%d%d%d",&n,&n1,&n2);
   scanf("%lf%lf%lf%lf",&a[n1].x,&a[n1].y,&a[n2].x,&a[n2].y);
   if (n1>n2)
      swap(n1,n2);
   double radius,angle;
   angle=2*pi*(n2-n1)/n;
   if (angle>pi)
      angle=2*pi-angle;
   radius=dist(a[n1],a[n2])/2/sin(angle/2);
   point o=solve(radius,n,n1,n2);
   angle=2*pi/n;
   for (int i=n1-1;i;i--)
      a[i]=rotate(a[i+1]-o,angle)+o;
   for (int i=n1+1;i<=n;i++)
      a[i]=rotate(a[i-1]-o,-angle)+o;
   for (int i=1;i<=n;i++)
      printf("%.6f %.6f\n",a[i].x+eps,a[i].y+eps);
   system("pause");
   return(0);
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
point solve(double radius,int n,int n1,int n2)
{
   point rotate(point,double);
   double angle=2*pi*(n2-n1)/n;
   if (fabs(angle-pi)<eps)
      return((a[n1]+a[n2])*0.5);
   if (angle<pi)
   {
      double theta=(pi-angle)/2;
      point t=rotate(a[n1]-a[n2],theta);
      return(a[n2]+t*(1/t.mod())*radius);
   }
   else
   {
      angle=2*pi-angle;
      double theta=(pi-angle)/2;
      point t=rotate(a[n1]-a[n2],-theta);
      return(a[n2]+t*(1/t.mod())*radius);
   }
}
point rotate(point p,double angle)
{
   return(point(p.x*cos(angle)-p.y*sin(angle),p.x*sin(angle)+p.y*cos(angle)));
}
