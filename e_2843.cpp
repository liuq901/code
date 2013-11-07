#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
struct rect
{
   ll x[10],y[10];
};
rect a,b;
ll ans,ansx,ansy;
int main()
{
   void update(ll,ll,ll,ll);
   for (int i=1;i<=4;i++)
      cin>>b.x[i]>>b.y[i];
   for (int i=1;i<=4;i++)
      cin>>a.x[i]>>a.y[i];
   sort(a.x+1,a.x+5);
   sort(a.y+1,a.y+5);
   sort(b.x+1,b.x+5);
   sort(b.y+1,b.y+5);
   ans=-1;
   for (int i=1;i<=4;i++)
      for (int j=1;j<=4;j++)
         for (int x=1;x<=4;x++)
            for (int y=1;y<=4;y++)
               update(i,j,x,y);
   cout<<ans<<endl<<ansx<<" "<<ansy<<endl;
   system("pause");
   return(0);
}
rect c;
ll x[10],y[10];
void update(ll ax,ll bx,ll ay,ll by)
{
   ll calc(ll,ll,ll,ll);
   for (int i=1;i<=4;i++)
   {
      c.x[i]=b.x[bx]+a.x[i]-a.x[ax];
      c.y[i]=b.y[by]+a.y[i]-a.y[ay];
   }
   for (int i=1;i<=4;i++)
   {
      x[i]=c.x[i],x[i+4]=b.x[i];
      y[i]=c.y[i],y[i+4]=b.y[i];
   }
   sort(x+1,x+9);
   sort(y+1,y+9);
   ll now=0;
   for (int i=1;i<8;i++)
      for (int j=1;j<8;j++)
         now+=calc(x[i],x[i+1],y[j],y[j+1]);
   if (now>ans)
   {
      ans=now;
      ansx=c.x[1]-a.x[1];
      ansy=c.y[1]-a.y[1];
   }
}
ll calc(ll x1,ll x2,ll y1,ll y2)
{
   bool hole(ll,ll,ll,ll),check(ll,ll,ll,ll);
   if (hole(x1,x2,y1,y2) || !check(x1,x2,y1,y2))
      return(0);
   return(ll(y2-y1)*(x2-x1));
}
bool hole(ll x1,ll x2,ll y1,ll y2)
{
   bool in(ll,ll,ll,ll);
   if (in(x1,x2,c.x[2],c.x[3]) && in(y1,y2,c.y[2],c.y[3]))
      return(true);
   if (in(x1,x2,b.x[2],b.x[3]) && in(y1,y2,b.y[2],b.y[3]))
      return(true);
   return(false);
}
bool check(ll x1,ll x2,ll y1,ll y2)
{
   bool in(ll,ll,ll,ll);
   if (!in(x1,x2,c.x[1],c.x[4]) || !in(y1,y2,c.y[1],c.y[4]))
      return(false);
   if (!in(x1,x2,b.x[1],b.x[4]) || !in(y1,y2,b.y[1],b.y[4]))
      return(false);
   return(true);
}
bool in(ll x1,ll x2,ll x3,ll x4)
{
   return(x1>=x3 && x2<=x4);
}
