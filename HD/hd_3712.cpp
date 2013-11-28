#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#define SQR(x) ((x)*(x))
using namespace std;
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
bool operator ==(point a,point b)
{
   return(fabs(a.x-b.x)<eps && fabs(a.y-b.y)<eps);
}
int main()
{
   void intersect(point,point,point,point,point &);
   bool check(point,point,point,point,point);
   double dist(point,point),dot(point,point);
   point reflect(point,point,point,point,double);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      point begin,end,direct,a[4];
      scanf("%lf%lf%lf%lf",&begin.x,&begin.y,&end.x,&end.y);
      for (int i=1;i<=3;i++)
         scanf("%lf%lf",&a[i].x,&a[i].y);
      double mu;
      scanf("%lf",&mu);
      direct=end-begin;
      int k1,k2;
      point P;
      double dis=1e100;
      k1=k2=-1;
      for (int i=1;i<=2;i++)
         for (int j=i+1;j<=3;j++)
         {
            point p;
            intersect(begin,end,a[i],a[j],p);
            if (!check(begin,end,a[i],a[j],p))
               continue;
            double len=dist(begin,p);
            if (len<dis)
            {
               dis=len;
               k1=i,k2=j;
               P=p;
            }
         }
      if (k1!=-1)
      {
         direct=reflect(P,direct,a[k1],a[k2],mu);
         int p1,p2;
         point p;
         bool flag=false;
         for (int i=1;i<=2;i++)
         {
            for (int j=i+1;j<=3;j++)
            {
               if (k1==i && k2==j)
                  continue;
               intersect(P,P+direct,a[i],a[j],p);
               if (check(P,P+direct,a[i],a[j],p))
               {
                  p1=i,p2=j;
                  flag=true;
                  break;
               }
            }
            if (flag)
               break;
         }
         direct=reflect(p,direct,a[p1],a[p2],1.0/mu);
         begin=p;
      }
      end=begin+direct;
      intersect(begin,end,point(0,0),point(1,0),P);
      if (P==point(-1,-1) || (dot(direct,P-begin)<0))
         printf("Error\n");
      else
         printf("%.3f\n",P.x);
   }
   system("pause");
   return(0);
}
void intersect(point u1,point u2,point v1,point v2,point &p)
{
   if (fabs((u1-u2)*(v1-v2))<eps)
   {
      p=point(-1,-1);
      return;
   }
   double t=(u1-v1)*(v1-v2)/((u1-u2)*(v1-v2));
   p=u1+(u2-u1)*t;
}
bool check(point A,point B,point C,point D,point P)
{
   double dot(point,point),dist(point,point);
   if (P==point(-1,-1))
      return(false);
   if (dot(P-A,B-A)<0)
      return(false);
   return(fabs(dist(C,D)-dist(C,P)-dist(D,P))<eps);
}
double dist(point a,point b)
{
   return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)));
}
point reflect(point P,point direct,point A,point B,double mu)
{
   double dot(point,point);
   point rotate(point,double);
   if (P==A || P==B)
      return(direct);
   if (dot(direct,A-B)<0)
      swap(A,B);
   point T=A-B;
   double angle=pi/2-acos(dot(direct,T)/direct.mod()/T.mod());
   double theta=asin(sin(angle)/mu);
   if (direct*T>0)
      return(rotate(direct,theta-angle));
   else
      return(rotate(direct,angle-theta));
}
double dot(point a,point b)
{
   return(a.x*b.x+a.y*b.y);
}
point rotate(point p,double x)
{
   return(point(p.x*cos(x)-p.y*sin(x),p.x*sin(x)+p.y*cos(x)));
}
