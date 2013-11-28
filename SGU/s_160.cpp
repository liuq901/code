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
const double eps=1e-7;
const double pi=acos(-1.0);
bool f[2][1010],g[10010][1010];
int a[10010],pre[10010][1010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   f[0][1]=true;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      for (int j=0;j<m;j++)
      {
         if (!f[i-1&1][j])
            continue;
         f[i-1&1][j]=false;
         f[i&1][j]=f[i&1][j*x%m]=true;
         pre[i][j]=j,g[i][j]=false;
         pre[i][j*x%m]=j,g[i][j*x%m]=true;
      }
   }
   int ans;
   for (int i=m-1;i>=0;i--)
      if (f[n&1][i])
      {
         ans=i;
         break;
      }
   printf("%d\n",ans);
   for (int i=n;i;i--)
   {
      if (g[i][ans])
         a[++a[0]]=i;
      ans=pre[i][ans];
   }
   for (int i=a[0];i;i--)
      printf("%d%c",a[i],i==1?'\n':' ');
   system("pause");
   return(0);
}
