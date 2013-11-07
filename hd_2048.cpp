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
ll a[21],c[21];
int main()
{
   void init();
   init();
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      printf("%.2f%%\n",a[n]*100.0/c[n]);
   }
   system("pause");
   return(0);
}
void init()
{
   a[1]=0,a[2]=1;
   for (int i=3;i<=20;i++)
      a[i]=(i-1)*(a[i-2]+a[i-1]);
   c[1]=1;
   for (int i=2;i<=20;i++)
      c[i]=c[i-1]*i;
}
