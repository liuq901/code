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
struct point
{
   double x,y,angle;
};
bool operator <(point a,point b)
{
   return(a.angle<b.angle);
}
point a[110];
double x[110],y[110];
int n,S;
int main()
{
   int work();
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%lf%lf",&x[i],&y[i]);
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      S=i;
      ans=max(ans,work());
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int f[110][110];
int work()
{
   double cross(double,double,double,double);
   int t=0;
   for (int i=1;i<=n;i++)
   {
      if (i==S || x[i]<x[S])
         continue;
      a[++t].x=x[i],a[t].y=y[i],a[t].angle=atan2(y[i]-y[S],x[i]-x[S]);
   }
   sort(a+1,a+t+1);
   memset(f,0,sizeof(f));
   int ans=0;
   for (int i=1;i<=t;i++)
      for (int j=i+1;j<=t;j++)
      {
         if (cross(a[j].x-a[i].x,a[j].y-a[i].y,x[S]-a[j].x,y[S]-a[j].y)<0)
            continue;
         f[i][j]=3;
         for (int k=1;k<i;k++)
         {
            if (cross(a[i].x-a[k].x,a[i].y-a[k].y,a[j].x-a[i].x,a[j].y-a[i].y)<0)
               continue;
            f[i][j]=max(f[i][j],f[k][i]+1);
         }
         ans=max(ans,f[i][j]);
      }
   return(ans);
}
double cross(double x1,double y1,double x2,double y2)
{
   return(x1*y2-x2*y1);
}
