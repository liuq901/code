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
int main()
{
   ll gcd(ll,ll);
   void ex_gcd(ll &,ll &,ll,ll,ll);
   ll x1,x2,p,k;
   cin>>x1>>x2>>p>>k;
   ll t=gcd(x1,x2);
   x1/=t,x2/=t;
   if (p%t)
      printf("NO\n");
   else
   {
      p/=t;
      ll x,y,bx,by;
      ex_gcd(x,y,x1,x2,p);
      bx=x+x2,by=y-x1;
      while (abs(bx)+abs(by)<abs(x)+abs(y))
      {
         x=bx,y=by;
         bx=x+x2,by=y-x1;
      }
      bx=x-x2,by=y+x1;
      while (abs(bx)+abs(by)<abs(x)+abs(y))
      {
         x=bx,y=by;
         bx=x-x2,by=y+x1;
      }
      bx=x,by=y;
      bool flag=false;
      for (int i=-5;i<=5;i++)
      {
         x=bx+i*x2;
         y=by-i*x1;
         if (abs(x)+abs(y)<=k && (abs(x)+abs(y)&1)==(k&1))
         {
            t=k-abs(x)-abs(y);
            printf("YES\n");
            ll a1,a2,a3,a4;
            a1=a2=a3=a4=0;
            x>0?a1=x:a2=-x;
            y>0?a3=y:a4=-y;
            a1+=t>>1,a2+=t>>1;
            cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;
            flag=true;
            break;
         }
      }
      if (!flag)
         printf("NO\n");
   }
   system("pause");
   return(0);
}
ll gcd(ll a,ll b)
{
   return(b?gcd(b,a%b):a);
}
void ex_gcd(ll &x,ll &y,ll a,ll b,ll c)
{
   if (!b)
   {
      x=c/a;
      y=0;
      return;
   }
   ll p,q;
   ex_gcd(p,q,b,a%b,c);
   x=q,y=p-(a/b)*q;
}
