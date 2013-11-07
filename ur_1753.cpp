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
const double pi=acos(-1.0);
const double eps=1e-9;
const int inf=1061109567;
double h,H;
int main()
{
   double calc(double);
   double L;
   scanf("%lf%lf%lf",&h,&H,&L);
   H/=2;
   double l=0,r=L;
   while (r-l>eps)
   {
      double x1=(2*l+r)/3,x2=(l+2*r)/3;
      if (calc(x1)<calc(x2))
         l=x1;
      else 
         r=x2;
   }
   printf("%.6lf\n",calc(l));
   system("pause");
   return(0);
}
double calc(double x)
{
   double s=sqrt(SQR(h)+SQR(x));
   return((H/s-1)*x);
}
