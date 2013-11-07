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
#define MAXN 110
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
   while (1)
   {
      int n,m;
      cin>>n>>m;
      if (!n && !m)
         break;
      int a[MAXN];
      for (int i=1;i<=n;i++)
         cin>>a[i];
      a[0]=m;
      sort(a,a+n+1);
      for (int i=0;i<n;i++)
         cout<<a[i]<<" ";
      cout<<a[n]<<endl;
   }
   system("pause");
   return(0);
}
