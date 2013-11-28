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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   while (1)
   {
      int n,m,a[60]={0};
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      int t=0,k;
      k=m;
      while (1)
      {
         if (!m)
         {
            m+=a[t];
            a[t]=0;
         }
         else
         {
            m--;
            a[t]++;
            if (a[t]==k)
            {
               printf("%d\n",t);
               break;
            }
         }
         t++;
         if (t==n)
            t=0;
      }
   }
   system("pause");
   return(0);
}
