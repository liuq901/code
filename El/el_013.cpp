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
#define MAXN 510
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
int li[MAXN],a[MAXN][3],b[MAXN][MAXN];
bool f[MAXN];
int main()
{
   bool hungary(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      sort(a[i],a[i]+3);
   }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         if (a[i][0]<a[j][0] && a[i][1]<a[j][1] && a[i][2]<a[j][2])
            b[i][++b[i][0]]=j;
   int ans=n;
   for (int i=1;i<=n;i++)
   {
      memset(f,0,sizeof(f));
      if (hungary(i))
         ans--;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=1;i<=b[x][0];i++)
   {
      int y=b[x][i];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(li[y]))
      {
         li[y]=x;
         return(true);
      }
   }
   return(false);
}
