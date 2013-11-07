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
int a[MAXN];
int main()
{
   void init();
   ios::sync_with_stdio(false);
   init();
   while (1)
   {
      int n;
      cin>>n;
      if (!n)
         break;
      cout<<a[n]<<endl;
   }
   system("pause");
   return(0);
}
void init()
{
   a[1]=1,a[2]=2,a[3]=3;
   for (int i=4;i<55;i++)
      a[i]=a[i-1]+a[i-3];
}
