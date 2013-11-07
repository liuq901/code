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
   int gcd(int,int);
   ios::sync_with_stdio(false);
   int n;
   while (cin>>n)
   {
      int a[MAXN];
      for (int i=1;i<=n;i++)
         cin>>a[i];
      if (n==1)
         cout<<a[1]<<endl;
      else
      {
         int p=gcd(a[1],a[2]);
         ll now=ll(a[1])*a[2]/p;
         for (int i=3;i<=n;i++)
         {
            int p=gcd(a[i],now);
            now=now*a[i]/p;
         }
         cout<<now<<endl;
      }
   }
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
