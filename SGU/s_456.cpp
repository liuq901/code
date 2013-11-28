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
   bool check(double,int,int,int);
   int s,m,p;
   scanf("%d%d%d",&s,&m,&p);
   double l=0,r=1e7;
   while (r-l>eps)
   {
      double mid=(l+r)/2;
      check(mid,s,p,m)?r=mid:l=mid;
   }
   printf("%f\n",l);
   system("pause");
   return(0);
}
bool check(double x,int S,int p,int m)
{
   double s=S;
   for (int i=1;i<=m;i++)
   {
      double rate=s*p/100.0;
      if (rate>x)
         return(false);
      s-=x-rate;
      if (s<eps)
         return(true);
   }
   return(false);
}
