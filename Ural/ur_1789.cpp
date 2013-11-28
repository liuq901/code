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
int ans[1010];
int main()
{
   int n;
   scanf("%d",&n);
   int m=0;
   for (int i=1;i<=n-1;i++)
      ans[i]=i;
   m=n-1;
   if (m&1)
      for (int i=1;i<=n-1;i++)
         ans[++m]=i;
   else
      for (int i=2;i<=n;i++)
         ans[++m]=i;
   printf("%d\n",m);
   for (int i=1;i<m;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[m]);
   system("pause");
   return(0);
}
