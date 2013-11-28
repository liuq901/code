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
#define MAXN 100010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
pair <int,int> a[MAXN];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d",&a[i].first,&a[i].second);
   sort(a+1,a+n+1);
   int ans=1;
   ll sum=a[1].first;
   for (int i=2;i<=n;i++)
      if (sum<=a[i].second)
         ans++,sum+=a[i].first;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
