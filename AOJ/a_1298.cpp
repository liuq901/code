#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
const double eps=1e-7;
struct point
{
   int x,y;
   point(){}
   point(int x,int y):x(x),y(y){}
};
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y));
}
ll operator *(point a,point b)
{
   return(ll(a.x)*b.y-ll(b.x)*a.y);
}
point black[110],white[110],a[110],b[110];
int suma,sumb;
int main()
{
   void convex(point *,point *,int,int &);
   bool check(point *,point,int),intersect(point,point,point,point);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d",&black[i].x,&black[i].y);
      for (int i=1;i<=m;i++)
         scanf("%d%d",&white[i].x,&white[i].y);
      convex(a,black,n,suma);
      convex(b,white,m,sumb);
      bool flag=true;
      for (int i=1;i<=suma;i++)
         if (!check(b,a[i],sumb))
         {
            flag=false;
            break;
         }
      for (int i=1;i<=sumb;i++)
         if (!check(a,b[i],suma))
         {
            flag=false;
            break;
         }
      for (int i=1;i<=suma;i++)
      {
         if (suma==1 || sumb==1)
            break;
         for (int j=1;j<=sumb;j++)
            if (intersect(a[i],a[i+1],b[j],b[j+1]))
            {
               flag=false;
               break;
            }
         if (!flag)
            break;
      }
      printf("%s\n",flag?"YES":"NO");
   }
   system("pause");
   return(0);
}
point now;
void convex(point *p,point *a,int n,int &m)
{
   bool comp(point,point);
   if (n==1)
   {
      m=1,p[1]=a[1];
      return;
   }
   else if (n==2)
   {
      m=2,p[1]=a[1],p[2]=a[2];
      return;
   }
   for (int i=1;i<=n;i++)
      if (a[i].x<a[1].x || a[i].x==a[1].x && a[i].y<a[1].y)
         swap(a[1],a[i]);
   now=a[1];
   sort(a+2,a+n+1,comp);
   m=1,p[1]=a[1];
   for (int i=2;i<=n;i++)
   {
      while (m>=2 && (p[m]-p[m-1])*(a[i]-p[m])<=0)
         m--;
      p[++m]=a[i];
   }
   while (m>=2 && (p[m]-p[m-1])*(p[1]-p[m])<=0)
      m--;
   p[m+1]=p[1];
}
bool comp(point a,point b)
{
   double dist(point,point);
   double p=atan2(a.y-now.y,a.x-now.x),q=atan2(b.y-now.y,b.x-now.x);
   if (fabs(p-q)<eps)
      return(dist(a,now)<dist(b,now));
   return(p<q);
}
bool check(point *a,point p,int n)
{
   double dist(point,point);
   ll abs(ll);
   if (n==1)
      return(true);
   else if (n==2)
   {
      if (fabs(dist(a[1],p)+dist(a[2],p)-dist(a[1],a[2]))<eps)
         return(false);
      return(true);
   }
   ll sum=0,area=0;
   for (int i=1;i<=n;i++)
   {
      sum+=abs((a[i+1]-p)*(a[i]-p));
      area+=(a[i+1]-p)*(a[i]-p);
   }
   if (abs(sum)==abs(area))
      return(false);
   return(true);
}
double dist(point a,point b)
{
   return(sqrt(double(SQR(ll(a.x-b.x))+SQR(ll(a.y-b.y)))));
}
ll abs(ll x)
{
   if (x<0)
      x=-x;
   return(x);
}
bool intersect(point u1,point u2,point v1,point v2)
{
   if ((v1-u1)*(u2-u1)*((v2-u1)*(u2-u1))>=0)
      return(false);
   if ((u1-v1)*(v2-v1)*((u2-v1)*(v2-v1))>=0)
      return(false);
   return(true);
}
