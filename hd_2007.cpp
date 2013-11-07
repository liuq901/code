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
   int n,m;
   while (cin>>n>>m)
   {
      int ans=0,sum=0;
      if (n>m)
         swap(n,m);
      for (int i=n;i<=m;i++)
         i&1?sum+=SQR(i)*i:ans+=SQR(i);
      cout<<ans<<" "<<sum<<endl;
   }
   system("pause");
   return(0);
}
