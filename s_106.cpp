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
ll ans,ma,mi;
int main()
{
   ll gcd(ll,ll,ll &,ll &);
   void update(ll,ll,ll);
   ll a,b,c,x1,y1,x2,y2;
   cin>>a>>b>>c>>x1>>x2>>y1>>y2;
   c=-c;
   if (!a && !b)
   {
      if (!c)
         ans=(x2-x1+1)*(y2-y1+1);
   }
   else if (!a)
   {
      ll t=c/b;
      if (!(c%b) && t>=y1 && t<=y2)
         ans=x2-x1+1;
   }
   else if (!b)
   {
      ll t=c/a;
      if (!(c%a) && t>=x1 && t<=x2)
         ans=y2-y1+1;
   }
   else
   {
      ll x,y,d=gcd(a,b,x,y);
      ma=1LL<<60,mi=-1LL<<60;
      if (!(c%d))
      {
         ll p=c/d;
         update(x1-p*x,x2-p*x,b/d);
         update(y1-p*y,y2-p*y,-a/d);
         ans=ma-mi+1;
         if (ans<0)
            ans=0;
      }
   }
   cout<<ans<<endl;
   system("pause");
   return(0);
}
ll gcd(ll a,ll b,ll &x,ll &y)
{
   if (!b)
   {
      x=1,y=0;
      return(a);
   }
   ll d=gcd(b,a%b,x,y),t=x;
   x=y,y=t-a/b*y;
   return(d);
}
void update(ll l,ll r,ll a)
{
   ll upper(ll,ll),lower(ll,ll);
   if (a<0)
   {
      l=-l,r=-r,a=-a;
      swap(l,r);
   }
   mi=max(mi,upper(l,a));
   ma=min(ma,lower(r,a));
}
ll upper(ll a,ll b)
{
   if (a<=0)
      return(a/b);
   return((a-1)/b+1);
}
ll lower(ll a,ll b)
{
   if (a>=0)
      return(a/b);
   return((a+1)/b-1);
}
