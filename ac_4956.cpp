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
ll c[1010],d[1010],e[1010],f[1010];
int a[1010][1010],b[1010][1010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&b[i][j]);
      srand(n);
      for (int i=1;i<=n;i++)
         c[i]=rand();
      memset(d,0,sizeof(d));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            d[i]+=a[i][j]*c[j];
      memset(e,0,sizeof(e));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            e[i]+=a[i][j]*d[j];
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            f[i]+=b[i][j]*c[j];
      bool flag=true;
      for (int i=1;i<=n;i++)
         if (e[i]!=f[i])
         {
            flag=false;
            break;
         }
      printf("%s\n",flag?"YES":"NO");
   }
   return(0);
}

