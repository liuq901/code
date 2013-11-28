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
bool f[1010],g[1010][1010];
int b[1010],e[20010][2],a[20010][2];
int main()
{
   void dfs(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      e[i][0]=x,e[i][1]=y;
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
   }
   for (int i=1;i<=n;i++)
   {
      memset(f,0,sizeof(f));
      dfs(i,i);
   }
   int ans=1;
   for (int i=1;i<=m;i++)
   {
      int x=e[i][0],y=e[i][1],now=0;
      for (int j=1;j<=n;j++)
         now+=g[x][j] && g[j][y];
      ans=max(ans,now);
   }
   b[0]=0;
   for (int i=1;i<=m;i++)
   {
      int x=e[i][0],y=e[i][1],now=0;
      for (int j=1;j<=n;j++)
         now+=g[x][j] && g[j][y];
      if (ans==now)
         b[++b[0]]=i;
   }
   printf("%d\n%d\n",ans,b[0]);
   for (int i=1;i<=b[0];i++)
      printf("%d%c",b[i],i==b[0]?'\n':' ');
   system("pause");
   return(0);
}
void dfs(int aim,int x)
{
   g[aim][x]=f[x]=true;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (!f[y])
         dfs(aim,y);
   }
}
