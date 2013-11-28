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
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      pair <int,int> a[MAXN];
      for (int i=1;i<=n;i++)
         scanf("%d%d",&a[i].second,&a[i].first);
      sort(a+1,a+n+1);
      int k=-1,ans=0;
      for (int i=1;i<=n;i++)
         if (a[i].second>=k)
         {
            ans++;
            k=a[i].first;
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
