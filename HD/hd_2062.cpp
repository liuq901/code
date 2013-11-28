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
   int n;
   ll m,f[30];
   f[0]=0;
   for (int i=1;i<=20;i++)
      f[i]=(i-1)*f[i-1]+1;
   while (cin>>n>>m)
   {
      int x[30];
      for (int i=0;i<=n;i++)
         x[i]=i;
      while (m)
      {
         int t=m/f[n]+(m%f[n]?1:0);
         printf("%d",x[t]);
         for (int i=t;i<n;i++)
            x[i]=x[i+1];
         m-=(t-1)*f[n]+1;
         printf("%c",m?' ':'\n');
         n--;
      }
   }
   system("pause");
   return(0);
}
