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
double X[30],Y[30],R[30],area[30];
int n;
int main()
{
   double work(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         scanf("%lf%lf%lf",&X[i],&Y[i],&R[i]);
         area[i]=SQR(R[i])*pi;
      }
      if (n==1)
         printf("%.4f\n",R[1]/sqrt(2));
      else
      {
         double ans=1e100;
         for (int i=1;i<=n;i++)
            ans=min(ans,work(i));
         printf("%.4f\n",ans);
      }
   }
   system("pause");
   return(0);
}
double work(int x)
{
   double dist(double,double,double,double);
   bool check(int,double);
   double l,r;
   l=r=0;
   for (int i=1;i<=n;i++)
   {
      double len=dist(X[x],Y[x],X[i],Y[i]);
      l=max(l,len),r=max(r,len+R[i]);
   }
   double ans;
   while (r-l>eps)
   {
      double mid=(l+r)/2;
      if (check(x,mid))
         ans=mid,r=mid;
      else
         l=mid;
   }
   return(ans);
}
bool check(int x,double radius)
{
   double count(int,int,double);
   for (int i=1;i<=n;i++)
   {
      if (i==x)
         continue;
      double Area=count(x,i,radius);
      if (Area*2<area[i])
         return(false);
   }
   return(true);
}
double count(int x,int y,double radius)
{
   void calc(double &,double &,double,double,double,double,double,double);
   double dist(double,double,double,double),did(double,double,double,double);
   double x1,y1,x2,y2;
   calc(x1,y1,X[x],Y[x],radius,X[y],Y[y],R[y]);
   calc(x2,y2,X[y],Y[y],R[y],X[x],Y[x],radius);
   double len=dist(x1,y1,x2,y2),angle;
   angle=asin(len/2/radius)*2;
   double area;
   area=SQR(radius)*angle/2;
   double now=did(X[x]-x1,Y[x]-y1,X[y]-x1,Y[y]-y1),tri;
   tri=did(x1-X[x],y1-Y[x],x2-X[x],y2-Y[x])/2;
   if (tri<now)
      angle=asin(len/2/R[y])*2;
   else
      angle=2*pi-asin(len/2/R[y])*2;
   area+=SQR(R[y])*angle/2-now;
   return(area);
}
void calc(double &x,double &y,double x1,double y1,double r1,double x2,double y2,double r2)
{
    double dx=x2-x1,dy=y2-y1;
    double D=sqrt(double(SQR(dx)+SQR(dy)));
    double E=(SQR(r1)-SQR(r2)+SQR(D))/(D*2);
    double F=sqrt(SQR(r1)-SQR(E));
    x=x1+(E*dx-F*dy)/D;
    y=y1+(F*dx+E*dy)/D;
}
double dist(double x1,double y1,double x2,double y2)
{
   return(sqrt(SQR(x1-x2)+SQR(y1-y2)));
}
double did(double x1,double y1,double x2,double y2)
{
   return(fabs(x1*y2-x2*y1));
}
