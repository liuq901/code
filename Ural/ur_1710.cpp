#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   int dist(int,int,int,int);
   bool check(int,int,int);
   void calc(int &,int &,int &,int,int,int,int,int,int);
   int x1,y1,x2,y2,x3,y3,a,b,c;
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
   c=dist(x1,y1,x2,y2);
   b=dist(x1,y1,x3,y3);
   a=dist(x2,y2,x3,y3);
   int x,y,t;
   calc(x,y,t,x1,y1,x3,y3,x2,y2);
   if (!check(a,b,c) && b+c>a && (abs(x1*t-x)>abs(x-x3*t) || abs(y1*t-y)>abs(y-y3*t)))
   {
      cout<<"NO"<<endl<<setprecision(15)<<fixed;
      int p,q;
      p=2*x-x3*t,q=2*y-y3*t;
      cout<<double(x1)<<" "<<double(y1)<<endl<<double(x2)<<" "<<double(y2)<<endl<<double(p)/t<<" "<<double(q)/t<<endl;
   }
   else
      cout<<"YES"<<endl;
   system("pause");
   return(0);
}
int dist(int x1,int y1,int x2,int y2)
{
   return(SQR(x1-x2)+SQR(y1-y2));
}
bool check(int a,int b,int c)
{
   return(a+b==c);
}
void calc(int &xx,int &yy,int &t,int x1,int y1,int x2,int y2,int x,int y)
{
   int a,b,c,d;
   a=y1-y2,b=x2-x1,c=x1*y2-x2*y1,d=a*y-b*x;
   xx=-a*c-b*d,yy=a*d-b*c,t=SQR(a)+SQR(b);
}
