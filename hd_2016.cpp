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
      int n;
      cin>>n;
      if (!n)
         break;
      int t=0,a[MAXN];
      a[0]=inf;
      for (int i=1;i<=n;i++)
      {
         cin>>a[i];
         if (a[i]<a[t])
            t=i;
      }
      swap(a[1],a[t]);
      for (int i=1;i<n;i++)
         cout<<a[i]<<" ";
      cout<<a[n]<<endl;
   }
   system("pause");
   return(0);
}
