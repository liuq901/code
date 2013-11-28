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
   point (double _x,double _y):x(_x),y(_y){}
   double mod()
   {
      return(sqrt(SQR(x)+SQR(y)));
   }
   point rotate()
   {
      return(point(-y,x));
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
point O,ans[10];
int tot;
int main()
{
   void work(point);
   point A,B,C;
   scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
   O=(A+B+C)*(1.0/3);
   work(A),work(B),work(C);
   for (int i=1;i<=6;i+=2)
      printf("%.10f %.10f\n",ans[i].x,ans[i].y);
   for (int i=2;i<=6;i+=2)
      printf("%.10f %.10f\n",ans[i].x,ans[i].y);
   system("pause");
   return(0);
}
void work(point A)
{
   double dist(point,point);
   double a,b,len,dis,height,c;
   len=dist(A,O);
   dis=sqrt(SQR(len)/(1.0/12+9.0/4));
   a=sqrt(3.0)/6*dis,b=1.5*dis;
   height=a*b/len;
   c=sqrt(SQR(a)-SQR(height));
   point P,Q,T;
   Q=O+(A-O)*(c/(A-O).mod());
   T=(A-O).rotate();
   P=Q+T*(height/T.mod());
   ans[++tot]=P+(O-P)*(dis*sqrt(3.0)/2/(O-P).mod());
   ans[++tot]=P+(P-O)*(dis*sqrt(3.0)/2/(P-O).mod());
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
