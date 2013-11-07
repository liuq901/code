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
int main()
{
   double x1,y1,x2,y2,x3,y3,x4,y4;
   while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
   {
      if (x1>x2)
         swap(x1,x2);
      if (y1>y2)
         swap(y1,y2);
      if (x3>x4)
         swap(x3,x4);
      if (y3>y4)
         swap(y3,y4);
      double ans=max(0.0,min(x2,x4)-max(x1,x3))*max(0.0,min(y2,y4)-max(y1,y3));
      printf("%.2f\n",ans);
   }
   system("pause");
   return(0);
}
