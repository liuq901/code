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
   double calc(double);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      double x1,y1,x2,y2;
      scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
      printf("%.2f\n",calc(atan2(y2,x2)-atan2(y1,x1)));
   }
   system("pause");
   return(0);
}
double calc(double angle)
{
   if (angle>2*pi)
      angle-=2*pi;
   if (angle<0)
      angle+=2*pi;
   if (angle>pi)
      angle=2*pi-angle;
   return(angle/pi*180);
}
