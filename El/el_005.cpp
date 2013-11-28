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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   char ch;
   double ans=0;
   int now=0;
   while (1)
   {
      while (cin.peek()==' ')
         cin.get();
      if (cin.peek()=='(')
         now++,cin.get();
      else if (cin.peek()==')')
         now--,cin.get();
      else
      {
         int x;
         cin>>x;
         ans+=x*pow(2.0,-now);
      }
      if (!now)
         break;
   }
   printf("%.2lf\n",ans);
   system("pause");
   return(0);
}
