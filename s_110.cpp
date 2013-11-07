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
   double x,y,z;
   point(){}
   point(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
   double mod()
   {
      return(sqrt(SQR(x)+SQR(y)+SQR(z)));
   }
};
struct circle
{
   point o;
   double radius;
};
point operator +(point a,point b)
{
   return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
double operator *(point a,point b)
{
   return(a.x*b.x+a.y*b.y+a.z*b.z);
}
point operator *(point a,double b)
{
   return(point(a.x*b,a.y*b,a.z*b));
}
circle a[60];
int main()
{
   bool work(point,point,circle,point &);
   double dist(point,point);
   point change(point,point,point);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%lf%lf%lf%lf",&a[i].o.x,&a[i].o.y,&a[i].o.z,&a[i].radius);
   point A,B;
   scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&A.z,&B.x,&B.y,&B.z);
   bool flag;
   for (int i=1;i<=10;i++)
   {
      flag=false;
      int k;
      point P,Q;
      for (int j=1;j<=n;j++)
      {
         if (!work(A,B,a[j],Q))
            continue;
         if (!flag || dist(A,Q)<dist(A,P))
         {
            P=Q,k=j;
            flag=true;
         }
      }
      if (!flag)
      {
         printf("\n");
         break;
      }
      if (i!=1)
         printf(" ");
      printf("%d",k);
      B=change(A,P,a[k].o);
      A=P;
   }
   if (flag)
   {
      flag=false;
      for (int i=1;i<=n;i++)
      {
         point P;
         if (work(A,B,a[i],P))
         {
            flag=true;
            break;
         }
      }
      if (flag)
         printf(" etc.");
      printf("\n");
   }
   system("pause");
   return(0);
}
bool work(point A,point B,circle C,point &P)
{
   double dist(point,point);
   point Q;
   double rate=(C.o-A)*(B-A)/SQR(B-A);
   Q=A+(B-A)*rate;
   if ((Q-A)*(B-A)<eps)
      return(false);
   double dis=dist(C.o,Q);
   if (fabs(dis-C.radius)<eps)
   {
      P=Q;
      return(true);
   }
   if (dis>C.radius)
      return(false);
   double len=sqrt(SQR(C.radius)-SQR(dis));
   P=Q+(A-B)*(len/(A-B).mod());
   return(true);
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)+SQR(a.z-b.z)));
}
point change(point A,point P,point O)
{
   double rate=(A-P)*(O-P)/SQR(O-P);
   point Q=P+(O-P)*rate;
   return(Q*2-A);
}
