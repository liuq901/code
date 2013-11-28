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
const double pi=acos(-1.0);
const double eps=1e-7;
int main()
{
   ios::sync_with_stdio(false);
   int n,m;
   while (cin>>n>>m)
   {
      bool flag=n<0;
      n=abs(n);
      int ans[MAXN],t=0;
      while (n)
      {
         ans[++t]=n%m;
         n/=m;
      }
      if (flag)
         cout<<"-";
      for (int i=t;i;i--)
         if (ans[i]<10)
            cout<<char(ans[i]+'0');
         else
            cout<<char(ans[i]-10+'A');
      cout<<endl;
   }
   system("pause");
   return(0);
}
