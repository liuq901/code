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
bool f[10];
int n,now[10];
int main()
{
   void dfs(int);
   scanf("%d",&n);
   dfs(1);
   system("pause");
   return(0);
}
void dfs(int dep)
{
   if (dep==n+1)
   {
      for (int i=1;i<n;i++)
         printf("%d ",now[i]);
      printf("%d\n",now[n]);
      return;
   }
   for (int i=1;i<=n;i++)
   {
      if (f[i])
         continue;
      f[i]=true;
      now[dep]=i;
      dfs(dep+1);
      f[i]=false;
   }
}
