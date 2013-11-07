#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#define SQR(x) ((x)*(x))
using namespace std;
struct edge
{
   int x,y;
   double value;
};
bool operator <(edge a,edge b)
{
   return(a.value<b.value);
}
edge a[260001];
multimap <pair <double,double> ,int> p,q;
typedef multimap <pair <double,double> ,int>::iterator data;
int N,M;
double X[20001],Y[20001];
int main()
{
   void calc(double &,double &,int,int,int,int,double,double),add(int,int);
   double work(int,int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      int ax,ay,bx,by,cx,cy,dx,dy;
      scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
      int tot=0;
      p.clear();
      for (int i=1;i<=n;i++)
      {
         double t,x,y;
         scanf("%lf",&t);
         x=ax*t+bx*(1-t);
         y=ay*t+by*(1-t);
         p.insert(make_pair(make_pair(x,y),++tot));
         X[tot]=x,Y[tot]=y;
      }
      q.clear();
      for (int i=1;i<=m;i++)
      {
         double t,x,y;
         scanf("%lf",&t);
         x=cx*t+dx*(1-t);
         y=cy*t+dy*(1-t);
         q.insert(make_pair(make_pair(x,y),++tot));
         X[tot]=x,Y[tot]=y;
      }
      N=n+m;
      M=0;
      for (data k=p.begin();k!=p.end();k++)
      {
         if (k!=p.begin())
         {
            data t=k;
            t--;
            add(t->second,k->second);
         }
         double xx,yy;
         calc(xx,yy,cx,cy,dx,dy,k->first.first,k->first.second);
         data t;
         t=q.lower_bound(make_pair(xx,yy));
         if (t!=q.end())
            add(k->second,t->second);
         if (t!=q.begin())
         {
            t--;
            add(k->second,t->second);
         }
      }
      for (data k=q.begin();k!=q.end();k++)
      {
         if (k!=q.begin())
         {
            data t=k;
            t--;
            add(t->second,k->second);
         }
         double xx,yy;
         calc(xx,yy,ax,ay,bx,by,k->first.first,k->first.second);
         data t;
         t=p.lower_bound(make_pair(xx,yy));
         if (t!=p.end())
            add(k->second,t->second);
         if (t!=p.begin())
         {
            t--;
            add(k->second,t->second);
         }
      }
      printf("Case #%d: %.3lf\n",id,work(N,M));
   }
   system("pause");
   return(0);
}
void calc(double &xx,double &yy,int x1,int y1,int x2,int y2,double m,double n)
{
   double a,b,c;
   if (y1!=y2)
      a=1,b=double(x1-x2)/(y2-y1),c=-a*x1-b*y1;
   else
      a=double(y1-y2)/(x2-x1),b=1,c=-a*x1-b*y1;
   xx=(b*b*m-a*b*n-a*c)/(a*a+b*b);
   yy=(a*a*n-a*b*m-b*c)/(a*a+b*b);
}
void add(int x,int y)
{
   double dist(double,double,double,double);
   a[++M].x=x,a[M].y=y,a[M].value=dist(X[x],Y[x],X[y],Y[y]);
}
double dist(double x1,double y1,double x2,double y2)
{
   return(sqrt(SQR(x1-x2)+SQR(y1-y2)));
}
int f[20001];
double work(int n,int m)
{
   int find(int);
   sort(a+1,a+m+1);
   for (int i=1;i<=n;i++)
      f[i]=i;
   int sum=0;
   double ans=0;
   for (int i=1;i<=m;i++)
   {
      int x=find(a[i].x),y=find(a[i].y);
      if (x==y)
         continue;
      ans+=a[i].value;
      f[x]=y;
      sum++;
      if (sum==n-1)
         break;
   }
   return(ans);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
