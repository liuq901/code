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
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int a[1001],b[1001];
int main()
{
   int t;
   scanf("%d",&t);
   for (int id=1;id<=t;id++)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
         scanf("%d",&b[i]);
      sort(a+1,a+n+1);
      sort(b+1,b+n+1);
      int ans=0,k=1;
      for (int i=1;i<=n;i++)
         if (a[i]>=b[k])
            ans++,k++;
      printf("Case %d: %d\n",id,ans);
   }
   system("pause");
   return(0);
}
