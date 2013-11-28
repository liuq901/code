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
#define MAXM 15010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
int b[MAXN],Link[MAXN],a[MAXM][2];
bool f[MAXN];
int main()
{
   bool hungary(int);
   int n,m,q;
   scanf("%d%d%d",&n,&m,&q);
   for (int i=1;i<=q;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
   }
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      memset(f,0,sizeof(f));
      ans+=hungary(i);
   }
   printf("%d\n",ans);
   for (int i=1;i<=m;i++)
      if (Link[i])
         printf("%d %d\n",Link[i],i);
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(Link[y]))
      {
         Link[y]=x;
         return(true);
      }
   }
   return(false);
}
