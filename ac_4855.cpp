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
#include <string>
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
const int m=46;
const double eps=1e-7;
const double pi=acos(-1.0);
int c[50];
int main()
{
   int calc(int);
   c[1]=1,c[2]=2;
   for (int i=2;i<=m;i++)
      c[i]=c[i-1]+c[i-2];
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      ll ans=1;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         ans*=calc(x);
      }
      static int id=0;
      printf("Case %d: %lld\n",++id,ans);
   }
   system("pause");
   return(0);
}
int calc(int x)
{
   int ans=0;
   for (int i=m;i;i--)
      while (x>=c[i])
      {
         x-=c[i];
         ans++;
      }
   return(ans);
}
