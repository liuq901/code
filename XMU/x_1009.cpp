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
int n,now;
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
   bool check(int);
   if (!check(now))
      return;
   if (dep==n+1)
   {
      printf("%d\n",now);
      return;
   }
   for (int i=1;i<=9;i++)
   {
      now=now*10+i;
      dfs(dep+1);
      now/=10;
   }
}
bool check(int x)
{
   if (!x || x==2 || x==3)
      return(true);
   if (x==1)
      return(false);
   int limit=int(sqrt(double(x)))+2;
   for (int i=2;i<=limit;i++)
      if (!(x%i))
         return(false);
   return(true);
}
