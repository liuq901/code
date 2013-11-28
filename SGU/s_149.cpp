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
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int who[10010],f[10010],g[10010],h[10010],b[10010],a[10010][3];
int main()
{
   void dfs(int,int),dp(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=i+1,a[i][1]=y,a[i][2]=b[x],b[x]=i;
   }
   dfs(1,0);
   dp(1,0);
   for (int i=1;i<=n;i++)
      printf("%d\n",max(f[i],h[i]));
   system("pause");
   return(0);
}
void dfs(int x,int father)
{
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      dfs(y,x);
      if (f[y]+a[i][1]>f[x])
      {
         g[x]=f[x];
         f[x]=f[y]+a[i][1];
         who[x]=y;
      }
      else if (f[y]+a[i][1]>g[x])
         g[x]=f[y]+a[i][1];
   }
}
void dp(int x,int father)
{
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      if (y==who[x])
         h[y]=max(h[x],g[x])+a[i][1];
      else
         h[y]=max(h[x],f[x])+a[i][1];
      dp(y,x);
   }
}
