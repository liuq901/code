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
int link[510],b[510],a[1010][2];
bool f[510];
int main()
{
   bool hungary(int);
   while (1)
   {
      int m;
      scanf("%d",&m);
      if (!m)
         break;
      int n;
      scanf("%d%*d",&n);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i][0]=y,a[i][1]=b[x],b[x]=i;
      }
      int ans=0;
      memset(link,0,sizeof(link));
      for (int i=1;i<=n;i++)
      {
         memset(f,0,sizeof(f));
         ans+=hungary(i);
      }
      printf("%d\n",ans);
   }
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
      if (hungary(link[y]))
      {
         link[y]=x;
         return(true);
      }
   }
   return(false);
}
