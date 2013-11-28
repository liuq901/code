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
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,p;
      scanf("%d%d",&n,&p);
      ll l,r;
      l=r=0;
      for (int i=1;i<n;i++)
      {
         int x;
         scanf("%d",&x);
         if (x>p)
            l+=x-p;
         else if (x<p)
            r+=p-x;
         p=x;
      }
      static int id=0;
      printf("Case %d: %I64d %I64d\n",++id,max(l,r),abs(l-r)+1);
   }
   system("pause");
   return(0);
}
