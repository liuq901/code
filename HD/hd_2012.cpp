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
   bool check(int);
   ios::sync_with_stdio(false);
   while (1)
   {
      int n,m;
      cin>>n>>m;
      if (!n && !m)
         break;
      bool flag=true;
      for (int i=n;i<=m;i++)
      {
         int t=i*i+i+41;
         if (!check(t))
         {
            flag=false;
            break;
         }
      }
      cout<<(flag?"OK":"Sorry")<<endl;
   }
   system("pause");
   return(0);
}
bool check(int x)
{
   if (x<2)
      return(false);
   int limit=int(sqrt(x)+0.5);
   for (int i=2;i<=limit;i++)
      if (!(x%i))
         return(false);
   return(true);
}
