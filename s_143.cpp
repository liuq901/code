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
int ans=-inf,f[16010],b[16010],c[16010],a[32010][2];
int main()
{
   void dfs(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&c[i]);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
   }
   dfs(1,0);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void dfs(int x,int father)
{
   f[x]=c[x];
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      dfs(y,x);
      f[x]=max(f[x],f[x]+f[y]);
   }
   ans=max(f[x],ans);
}
