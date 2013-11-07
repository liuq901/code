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
#define MAXN 10010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int ans[MAXN];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
bool f[MAXN];
int a[MAXN],s[MAXN];
void init()
{
   int n=MAXN-10;
   f[1]=true;
   for (int i=2;i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   a[0]=0;
   for (int i=1;i<=n;i++)
      if (!f[i])
      {
         a[++a[0]]=i;
         s[a[0]]=s[a[0]-1]+a[a[0]];
      }
   for (int i=0;i<=a[0];i++)
      for (int j=i+1;j<=a[0];j++)
         if (s[j]-s[i]<=n)
            ans[s[j]-s[i]]++;
}
