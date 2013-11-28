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
#include <string>
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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
struct ApocalypseSomeday
{
   int getNth(int n)
   {
      int sum=0,now=666;
      while (1)
      {
         if (check(now))
            sum++;
         if (sum==n)
            return(now);
         now++;
      }
   }
private:
   bool check(int x)
   {
      int a[10];
      a[0]=0;
      while (x)
      {
         a[++a[0]]=x%10;
         x/=10;
      }
      for (int i=3;i<=a[0];i++)
         if (a[i-2]==6 && a[i-1]==6 && a[i]==6)
            return(true);
      return(false);
   }
};
int main()
{
   int n;
   scanf("%d",&n);
   ApocalypseSomeday p;
   printf("%d\n",p.getNth(n));
   system("pause");
   return(0);
}
