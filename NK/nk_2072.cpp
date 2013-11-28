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
   int id=0;
   while (1)
   {
      int n,m;
      scanf("%d%*d%d",&n,&m);
      if (!n && !m)
         break;
      double sum=0;
      for (int i=1;i<=n;i++)
      {
         double x;
         int y;
         scanf("%lf%d",&x,&y);
         sum+=x*(100-y)/100;
      }
      printf("Case %d: %.2lf\n\n",++id,sum/m);
   }
   system("pause");
   return(0);
}
