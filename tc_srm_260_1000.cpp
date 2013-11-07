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
struct AmountApproximation
{
   int approximate(int d,int p1,int p2)
   {
      if (p1<p2)
         swap(p1,p2);
      ll time=min(d/p1+1,p2),ans=10LL*inf;
      for (ll i=0;i<=time;i++)
      {
         if (d<=p1*i)
         {
            ans=min(ans,p1*i);
            continue;
         }
         if (!((d-p1*i)%p2))
            return(d);
         ans=min(ans,p1*i+((d-p1*i)/p2+1)*p2);
      }
      return(int(ans));
   }
};
int main()
{
   int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
   AmountApproximation p;
   printf("%d\n",p.approximate(a,b,c));
   system("pause");
   return(0);
}
