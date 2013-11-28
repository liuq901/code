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
double operator *(point a,point b)
{
   return(a.x*b.y-b.x*a.y);
}
bool operator <(point a,point b)
{
   return(a.x<b.x+eps);
}
point begin,end,A[2010],B[2010];
int n,L;
int main()
{
   bool check(double);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d",&n,&L);
      begin=point(-inf,0),end=point(inf,0);
      for (int i=1;i<=n;i++)
         scanf("%lf%lf%lf%lf",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
      double l=0,r=30000;
      while (r-l>eps)
      {
         double mid=(l+r)/2;
         if (check(mid))
            l=mid;
         else
            r=mid;
      }
      printf("%.3f\n",l);
   }
   system("pause");
   return(0);
}
double R;
int tot;
pair <double,double> a[2010];
bool check(double tmp)
{
   void work(point,point);
   R=tmp;
   tot=0;
   for (int i=1;i<=n;i++)
      work(A[i],B[i]);
   sort(a+1,a+tot+1);
   int t=0;
   while (t<=tot && a[t].second<eps)
      t++;
   if (t>tot)
      return(true);
   if (a[t].first>eps)
      return(true);
   double last=a[t].second;
   for (int i=t+1;i<=tot;i++)
   {
      if (last+eps>=L)
         return(false);
      if (a[i].first+eps>last)
         return(true);
      last=max(last,a[i].second);
   }
   return(last<L+eps);
}
void work(point A,point B)
{
   point move(point,point,double),rotate(point);
   bool intersect(point,point,point,point,point &);
   double dist(point,point,point);
   void intersection(point,double,point,point,point &,point &);
   point C,D,E,F,T,t1,t2;
   C=move(A,rotate(B-A),R);
   D=move(B,rotate(B-A),R);
   E=move(A,rotate(A-B),R);
   F=move(B,rotate(A-B),R);
   point P=end,Q=begin;
   if (intersect(C,D,begin,end,T))
      P=min(P,T),Q=max(Q,T);
   if (intersect(E,F,begin,end,T))
      P=min(P,T),Q=max(Q,T);
   if (dist(A,begin,end)<R+eps)
   {
      intersection(A,R,begin,end,t1,t2);
      P=min(P,t1),Q=max(Q,t1),P=min(P,t2),Q=max(Q,t2);
   }
   if (dist(B,begin,end)<R+eps)
   {
      intersection(B,R,begin,end,t1,t2);
      P=min(P,t1),Q=max(Q,t1),P=min(P,t2),Q=max(Q,t2);
   }
   if (P<Q)
      a[++tot]=make_pair(P.x,Q.x);
}
point move(point A,point t,double R)
{
   if (t.mod()<eps)
      return(A);
   return(A+t*(R/t.mod()));
}
point rotate(point t)
{
   return(point(-t.y,t.x));
}
double dist(point p,point l1,point l2)
{
   double dist(point,point);
   return(fabs((p-l2)*(l1-l2))/dist(l1,l2));
}
void intersection(point c,double r,point l1,point l2,point &p1,point &p2)
{
   bool intersect(point,point,point,point,point &);
   double dist(point,point);
   point p=c;
   double t;
   p.x+=l1.y-l2.y;
   p.y+=l2.x-l1.x;
   point T=p;
   intersect(T,c,l1,l2,p);
   t=sqrt(SQR(r)-SQR(dist(p,c)))/dist(l1,l2);
   p1=p+(l2-l1)*t;
   p2=p-(l2-l1)*t;
}
bool intersect(point u1,point u2,point v1,point v2,point &P)
{
   double dist(point,point);
   bool check(point,point,point);
   if (dist(u1,u2)<eps)
      return(false);
   if (fabs(u1.y-u2.y)<eps)
      return(false);
   double t=((u1-v1)*(v1-v2))/((u1-u2)*(v1-v2));
   P=u1+(u2-u1)*t;
   return(check(P,u1,u2) && check(P,v1,v2));
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
bool check(point P,point a,point b)
{
   return(P.x+eps>=min(a.x,b.x) && P.x<=max(a.x,b.x)+eps && P.y+eps>=min(a.y,b.y) && P.y<=max(a.y,b.y)+eps);
}
