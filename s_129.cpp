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
   int x,y;
   double angle;
   point(){}
   point(int _x,int _y):x(_x),y(_y){}
};
struct Tpoint
{
   double x,y;
   Tpoint(){}
   Tpoint(point &a)
   {
      x=a.x,y=a.y;
   }
};
ll operator *(point a,point b)
{
   return(a.x*ll(b.y)-b.x*ll(a.y));
}
point operator -(point &a,point &b)
{
   return(point(a.x-b.x,a.y-b.y));
}
bool operator <(point a,point b)
{
   return(a.angle<b.angle);
}
bool operator !=(Tpoint &a,point &b)
{
   return(fabs(a.x-b.x)>eps || fabs(a.y-b.y)>eps);
}
point a[410];
ll area;
int n;
int main()
{
   double work(point &,point &);
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i].x,&a[i].y);
      if (a[i].x<a[1].x || a[i].x==a[1].x && a[i].y<a[1].y)
         swap(a[i],a[1]);
   }
   for (int i=2;i<=n;i++)
      a[i].angle=atan2(a[i].y-a[1].y,a[i].x-a[1].x);
   sort(a+2,a+n+1);
   a[0]=a[n];
   for (int i=1;i<=n;i++)
      area+=a[i-1]*a[i];
   area=abs(area);
   int m;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
      point A,B;
      scanf("%d%d%d%d",&A.x,&A.y,&B.x,&B.y);
      printf("%f\n",work(A,B));
   }
   system("pause");
   return(0);
}
double work(point &A,point &B)
{
   bool check(Tpoint &,point &,point &),in(point &);
   Tpoint intersection(point &,point &,point &,point &);
   double dist(Tpoint,Tpoint);
   for (int i=1;i<=n;i++)
      if (!((a[i-1]-A)*(a[i]-A)) && !((a[i-1]-B)*(a[i]-B)))
         return(0);
   Tpoint P[2];
   int sum=0;
   for (int i=1;i<=n;i++)
   {
      if (!((A-B)*(a[i-1]-a[i])))
         continue;
      Tpoint X;
      X=intersection(A,B,a[i-1],a[i]);
      if (check(X,A,B) && check(X,a[i-1],a[i]) && X!=a[i-1])
         P[sum++]=X;
      if (sum==2)
         break;
   }
   bool fa=in(A),fb=in(B);
   if (sum==2)
      return(dist(P[0],P[1]));
   if (!sum)
      return(fa && fb?dist(A,B):0);
   if (fa)
      return(dist(A,P[0]));
   if (fb)
      return(dist(B,P[0]));
   return(0);
}
bool check(Tpoint &x,point &a,point &b)
{
   return(x.x+eps>=min(a.x,b.x) && x.x-eps<=max(a.x,b.x) && x.y+eps>=min(a.y,b.y) && x.y-eps<=max(a.y,b.y));
}
bool in(point &p)
{
   ll now=0;
   for (int i=1;i<=n;i++)
   {
      now+=abs((a[i-1]-p)*(a[i]-p));
      if (!((a[i-1]-p)*(a[i]-p)))
         return(false);
   }
   return(now==area);
}
Tpoint intersection(point &u1,point &u2,point &v1,point &v2)
{
   double t=double((u1-v1)*(v1-v2))/((u1-u2)*(v1-v2));
   Tpoint now;
   now.x=u1.x+(u2.x-u1.x)*t;
   now.y=u1.y+(u2.y-u1.y)*t;
   return(now);
}
double dist(Tpoint a,Tpoint b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
