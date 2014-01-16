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
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
int main()
{
   int n,a[1000];
   scanf("%d",&n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   sort(a,a+n);
   for (int i=0;i<n-1;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n-1]);
   system("pause");
   return(0);
}
