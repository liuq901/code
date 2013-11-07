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
const int mod=100;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   int power(int,ll);
   while (1)
   {
      int test;
      scanf("%d",&test);
      if (!test)
         break;
      for (int id=1;id<=test;id++)
      {
         ll n;
         cin>>n;
         int ans=(power(4,n-1)+power(2,n-1))%mod;
         printf("Case %d: %d\n",id,ans);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
int power(int x,ll n)
{
   if (!n)
      return(1);
   int ret=power(x,n>>1);
   ret*=ret;
   if (n&1)
      ret*=x;
   return(ret%mod);
}
