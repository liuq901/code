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
int f[MAXN][MAXN];
int main()
{
   int n,ans=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=i;j++)
      {
         int x;
         scanf("%d",&x);
         f[i][j]=max(f[i-1][j-1],f[i-1][j])+x;
         ans=max(ans,f[i][j]);
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
