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
   ios::sync_with_stdio(false);
   int n;
   while (cin>>n)
   {
      int sum=0,ans=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         cin>>x;
         if (!sum)
            sum=1,ans=x;
         else
            sum+=ans==x?1:-1;
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
