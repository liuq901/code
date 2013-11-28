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
#define MAXN 110
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int n;
double x[MAXN],y[MAXN],r[MAXN];
int main()
{
   bool check(int,int);
   void calc(double &,double &,double,double,double,double,double,double);
   int count(double,double);
   while (scanf("%d",&n)!=EOF)
   {
      for (int i=1;i<=n;i++)
         scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=n;j++)
         {
            if (!check(i,j))
               continue;
            double x0,y0;
            calc(x0,y0,x[i],y[i],r[i],x[j],y[j],r[j]);
            ans=max(ans,count(x0,y0));
         }
         ans=max(ans,count(x[i],y[i]));
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool check(int i,int j)
{
   double d=SQR(x[i]-x[j])+SQR(y[i]-y[j]);
   if (fabs(d)<eps)
      return(false);
   return(d<=SQR(r[i]+r[j])+eps && d>=SQR(r[i]-r[j])-eps);
}
void calc(double &x,double &y,double x1,double y1,double r1,double x2,double y2,double r2)
{
   double dx,dy,D,E,F;
   dx=x2-x1,dy=y2-y1;
   D=sqrt(SQR(dx)+SQR(dy));
   E=(SQR(r1)-SQR(r2)+SQR(D))/(D*2);
   F=sqrt(SQR(r1)-SQR(E));
   x=x1+(E*dx-F*dy)/D;
   y=y1+(F*dx+E*dy)/D;
}
int count(double x0,double y0)
{
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      double len=SQR(x0-x[i])+SQR(y0-y[i]);
      ans+=len<=SQR(r[i])+eps;
   }
   return(ans);
}
