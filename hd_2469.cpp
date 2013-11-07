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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct point
{
   int x,y,len;
   double angle;
};
bool operator <(point a,point b)
{
   return(a.angle<b.angle);
}
point a[5010];
int pos[5010];
int main()
{
   double check(double);
   int id=0;
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i].x,&a[i].y);
         a[i].len=SQR(a[i].x)+SQR(a[i].y);
         a[i].angle=atan2(a[i].y,a[i].x);
      }
      sort(a+1,a+n+1);
      double ans=1e100;
      for (int i=1;i<=n;i++)
      {
         if (!m)
         {
            ans=0;
            break;
         }
         int t=0;
         for (int j=1;j<=n;j++)
            if (a[j].len<=a[i].len)
               pos[++t]=j;
         if (t<m)
            continue;
         double radius=sqrt(double(a[i].len));
         for (int j=1;j<=t;j++)
         {
            if (j!=1 && fabs(a[pos[j]].angle-a[pos[j-1]].angle)<eps)
               continue;
            int limit=j+m-1;
            if (limit>t)
               limit-=t;
            double angle=check(a[pos[limit]].angle-a[pos[j]].angle);
            ans=min(ans,SQR(radius)*angle);
         }
      }
      printf("Case #%d: %.2lf\n",++id,ans/2.0);
   }
   system("pause");
   return(0);
}
double check(double x)
{
   if (x<0)
      x+=2*pi;
   if (x>2*pi)
      x-=2*pi;
   return(x);
}
