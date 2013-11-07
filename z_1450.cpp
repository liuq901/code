#include <cstdio>
#include <cstdlib>
#include <cmath>
const double pi=3.1415926535897;
struct point
{
   double x,y;
   double mod()
   {
      return(sqrt(x*x+y*y));
   }
};
bool operator ==(point a,point b)
{
   if (fabs(a.x-b.x)<1e-8 && fabs(a.y-b.y)<1e-8)
      return(true);
   else
      return(false);
}
bool operator !=(point a,point b)
{
   if (a==b)
      return(false);
   else
      return(true);
}
point operator -(point a,point b)
{
   point ans;
   ans.x=a.x-b.x;
   ans.y=a.y-b.y;
   return(ans);
}
double operator *(point a,point b)
{
   return(a.x*b.x+a.y*b.y);
}
int main()
{
   void work(int);
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (n==0)
         break;
      work(n);
   }
   system("pause");
   return(0);
}
double r;
point o,p[101];
void work(int n)
{
   point mid(point,point);
   double dis(point,point);
   void get(point,point,int);
   for (int i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
   if (n==1)
   {
      printf("%.2lf %.2lf 0.00\n",p[1].x,p[1].y);
      return;
   }
   o=mid(p[1],p[2]);
   r=dis(p[1],p[2])/2;
   for (int i=3;i<=n;i++)
   {
      if (dis(o,p[i])<r)
         continue;
      r=20000000;
      for (int j=1;j<=i-1;j++)
         get(p[i],p[j],i-1);
   }
   printf("%.2lf %.2lf %.2lf\n",o.x,o.y,r);
}
void get(point a,point b,int n)
{
   point find(point,point,point),mid(point,point);
   double dis(point,point);
   double k,t;
   if (a.x==b.x)
      return;
   k=(a.y-b.y)/(a.x-b.x);
   t=a.y-k*a.x;
   double alpha=pi,beta=pi;
   point p1=a,p2=b;
   for (int i=1;i<=n;i++)
   {
      if (p[i]==a || p[i]==b)
         continue;
      point u,v;
      u=a-p[i];
      v=b-p[i];
      double theta;
      theta=acos(u*v/(u.mod()*v.mod()));
      if (p[i].x*k+t>=p[i].y && theta<alpha)
      {
         alpha=theta;
         p1=p[i];
      }
      if (p[i].x*k+t<p[i].y && theta<beta)
      {
         beta=theta;
         p2=p[i];
      }
   }
   if (alpha+beta<pi)
      return;
   point o1,o2;
   o1=find(a,b,p1);
   o2=find(a,b,p2);
   if (p1!=a && dis(o1,p1)<r)
   {
      o=o1;
      r=dis(o1,p1);
   }
   if (p2!=b && dis(o2,p2)<r)
   {
      o=o2;
      r=dis(o2,p2);
   }
   if (alpha>pi/2 && beta>pi/2 && dis(a,b)/2<r)
   {
      o=mid(a,b);
      r=dis(a,b)/2;
   }
}
point find(point x,point y,point z)
{
   point mid(point,point);
   if (x==y)
      return(mid(x,z));
   if (x==z || y==z)
      return(mid(x,y));
   point p1,p2;
   p1=mid(x,y);
   p2=mid(x,z);
   point u,v;
   u=y-x;
   v=z-x;
   double t1,t2;
   t1=p1*u;
   t2=p2*v;
   point ans;
   ans.x=(t1*v.y-t2*u.y)/(u.x*v.y-v.x*u.y);
   ans.y=(t1*v.x-t2*u.x)/(u.y*v.x-v.y*u.x);
   return(ans);
}
point mid(point x,point y)
{
   point ans;
   ans.x=(x.x+y.x)/2;
   ans.y=(x.y+y.y)/2;
   return(ans);
}
double dis(point a,point b)
{
   return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
