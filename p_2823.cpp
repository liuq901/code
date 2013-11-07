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
#define MAXN 1000010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
int a[MAXN],q[MAXN];
int main()
{
   int n,k;
   scanf("%d%d",&n,&k);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   int l,r;
   l=1,r=0;
   for (int i=1;i<=n;i++)
   {
      while (l<=r && a[i]<=a[q[r]])
         r--;
      q[++r]=i;
      if (q[l]<=i-k)
         l++;
      if (i>=k)
         printf("%d%c",a[q[l]],i==n?'\n':' ');
   }
   l=1,r=0;
   for (int i=1;i<=n;i++)
   {
      while (l<=r && a[i]>=a[q[r]])
         r--;
      q[++r]=i;
      if (q[l]<=i-k)
         l++;
      if (i>=k)
         printf("%d%c",a[q[l]],i==n?'\n':' ');
   }
   system("pause");
   return(0);
}
