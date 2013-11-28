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
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   int gcd(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int x,y;
      scanf("%d.%d",&x,&y);
      bool flag=true;
      if (y!=0 && y!=50 && y!=25 && y!=75)
         flag=false;
      int n,a[MAXN];
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      if (!flag)
         printf("no\n");
      else
      {
         x=(x*100+y<<2)/100;
         while (!(x&1))
            x>>=1;
         int p=a[1];
         for (int i=2;i<=n;i++)
            p=gcd(p,a[i]);
         while (!(p&1))
            p>>=1;
         printf("%s\n",x%p?"no":"yes");
      }
   }
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
