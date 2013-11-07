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
#define MAXN 110
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   ios::sync_with_stdio(false);
   int n,m;
   while (cin>>n>>m)
   {
      int a[MAXN];
      a[0]=0;
      for (int i=1;i<=n;i++)
         a[i]=a[i-1]+2;
      int t=1;
      while (t<=n)
      {
         int sum,s;
         sum=s=0;
         for (int i=1;i<=m;i++)
         {
            if (t+i-1>n)
               break;
            sum+=a[t+i-1];
            s++;
         }
         t+=m;
         cout<<sum/s<<(t<=n?" ":"");
      }
      cout<<endl;
   }
   system("pause");
   return(0);
}
