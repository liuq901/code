#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
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
const int inf=(1<<30)-1;
const double eps=1e-7;
const double pi=acos(-1);
int main()
{
   ios::sync_with_stdio(false);
   while (1)
   {
      ll n,m;
      cin>>n>>m;
      if (!n && !m)
         break;
      if (!n || !m)
      {
         cout<<1<<endl;
         continue;
      }
      if (n==1 || m==1)
      {
         cout<<n+m<<endl;
         continue;
      }
      double ans=1;
      for (ll i=1;i<=min(n,m);i++)
         ans=ans*(n+m-i+1)/i;
      cout<<setprecision(0)<<fixed<<ans<<endl;
   }
   system("pause");
   return(0);
}
