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
typedef set <int>::iterator data;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
set <int> a,b;
int main()
{
   int x;
   while (1)
   {
      scanf("%d",&x);
      if (x==-1)
         break;
      a.insert(x);
   }
   while (1)
   {
      scanf("%d",&x);
      if (x==-1)
         break;
      if (a.count(x))
         b.insert(x);
   }
   if (b.empty())
      printf("empty\n");
   else
   {
      for (data k=b.begin();k!=b.end();k++)
      {
         if (k!=b.begin())
            printf(" ");
         printf("%d",*k);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
