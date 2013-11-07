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
   int t;
   scanf("%d",&t);
   while (t--)
   {
      ll ans[51];
      int a,b;
      scanf("%d%d",&a,&b);
      ans[a]=ans[a+1]=1;
      for (int i=a+2;i<=b;i++)
         ans[i]=ans[i-1]+ans[i-2];
      cout<<ans[b]<<endl;
   }
   system("pause");
   return(0);
}
