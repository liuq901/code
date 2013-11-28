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
double operator *(point a,point b)
{
   return(a.x*b.y-b.x*a.y);
}
double radius,rate;
int main()
{
   void work(point &,point &);
   bool check(point,point,point,point);
   point p1,p2,q1,q2;
   scanf("%lf%lf",&radius,&rate);
   point p,q;
   work(p1,p2);
   work(q1,q2);
   printf("%s\n",check(p1,p2,q1,q2)?"Yes":"No");
   system("pause");
   return(0);
}
void work(point &ans1,point &ans2)
{
   void intersection(double,point,point,point &,point &);
   double dist(point,point),calc(double),sign(double);
   point rotate(point,double);
   double x,y,a,b;
   scanf("%lf%lf%lf%lf",&x,&y,&a,&b);
   point p(x,y),q(x+a,y+b),jiao1,jiao2;
   intersection(radius,p,q,jiao1,jiao2);
   point t;
   t=dist(p,jiao1)<dist(p,jiao2)?jiao1:jiao2;
   double theta=calc(atan2(t.y,t.x)-atan2(t.y-y,t.x-x));
   double beta=asin(sin(fabs(theta))/rate)*sign(theta);
   point now(-t.x,-t.y);
   now=rotate(now,beta);
   ans1=t,ans2=point(t.x+now.x,t.y+now.y);
}
void intersection(double r,point l1,point l2,point &p1,point &p2)
{
   point intersection(point,point,point,point);
   double dist(point,point);
   point p,c(0,0);
   p.x=l1.y-l2.y;
   p.y=l2.x-l1.x;
   p=intersection(p,c,l1,l2);
   double t=sqrt(SQR(r)-SQR(dist(p,c)))/dist(l1,l2);
   p1=p+(l2-l1)*t;
   p2=p-(l2-l1)*t;
}
double calc(double x)
{
   double sign(double);
   if (x<0)
      x+=2*pi;
   if (x>2*pi)
      x-=2*pi;
   double t=fabs(x);
   if (t>pi/2)
      t=pi-t;
   return(t*sign(x));
}
double sign(double x)
{
   if (x<0)
      return(-1);
   return(1);
}
point rotate(point p,double angle)
{
   point ret;
   ret.x=p.x*cos(angle)-p.y*sin(angle);
   ret.y=p.x*sin(angle)+p.y*cos(angle);
   return(ret);
}
bool check(point p1,point p2,point q1,point q2)
{
   bool check(point);
   point intersection(point,point,point,point);
   if (fabs((q1-p1)*(q1-p2))<eps && fabs((q2-p1)*(q2-p2))<eps)
      return(true);
   if (fabs((q2-q1)*(p2-p1))<eps)
      return(false);
   return(check(intersection(p1,p2,q1,q2)));
}
bool check(point p)
{
   double dist(point,point);
   return(dist(p,point(0,0))<radius);
}
double dist(point p1,point p2)
{
   return(sqrt(SQR(p1.x-p2.x)+SQR(p1.y-p2.y)));
}
point intersection(point u1,point u2,point v1,point v2)
{
   double t=(u1-v1)*(v1-v2)/((u1-u2)*(v1-v2));
   return(u1+(u2-u1)*t);
}
