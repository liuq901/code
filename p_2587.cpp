#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
const double radius=2026;
double x[MAXN],y[MAXN],d[MAXN][MAXN];
int main()
{
   double dist(double,double,double,double);
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   for (int i=1;i<=n;i++)
      cin>>x[i]>>y[i];
   for (int i=1;i<=n;i++)
      for (int j=i;j<=n;j++)
         d[i][j]=d[j][i]=dist(x[i],y[i],x[j],y[j]);
   double ans=1e100;
   int t;
   for (int i=1;i<=n;i++)
   {
      double Max=0;
      for (int j=1;j<=n;j++)
         Max=max(Max,d[i][j]);
      if (Max<ans)
         ans=Max,t=i;
   }
   cout<<setprecision(2)<<fixed<<x[t]<<" "<<y[t]<<endl;
   system("pause");
   return(0);
}
double dist(double wei1,double jin1,double wei2,double jin2)
{
   void calc(double,double,double &,double &,double &);
   double x1,y1,z1,x2,y2,z2;
   calc(wei1,jin1,x1,y1,z1);
   calc(wei2,jin2,x2,y2,z2);
   return(sqrt(double(SQR(x1-x2)+SQR(y1-y2)+SQR(z1-z2))));
}
void calc(double wei,double jin,double &x,double &y,double &z)
{
   double change(double);
   double Radius=radius*cos(change(fabs(wei)));
   if (jin>=0 && jin<=90)
   {
      x=Radius*sin(change(jin));
      y=-Radius*cos(change(jin));
   }
   else if (jin>=90 && jin<=180)
   {
      x=Radius*sin(change(180-jin));
      y=Radius*cos(change(180-jin));
   }
   else if (jin<=0 && jin>=-90)
   {
      x=-Radius*sin(change(-jin));
      y=-Radius*cos(change(-jin));
   }
   else
   {
      x=-Radius*sin(change(180+jin));
      y=Radius*cos(change(180+jin));
   }
   if (wei>=0)
      z=radius*sin(change(wei));
   else
      z=-radius*sin(change(-wei));
}
double change(double angle)
{
   return(angle/180*pi);
}
