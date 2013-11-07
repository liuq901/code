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
const int a[]={100,50,10,5,2,1};
int main()
{
   int calc(int);
   ios::sync_with_stdio(false);
   while (1)
   {
      int n;
      cin>>n;
      if (!n)
         break;
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         cin>>x;
         ans+=calc(x);
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
int calc(int x)
{
   int t=0,sum=0;
   while (x)
   {
      while (x<a[t])
         t++;
      x-=a[t];
      sum++;
   }
   return(sum);
}
