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
#define MAXN 10
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
bool f[MAXN],a[MAXN][MAXN],b[MAXN][MAXN];
int n,ia,ib,da,db,ans,pos[MAXN];
int main()
{
   void dfs(int);
   int id=0;
   while (1)
   {
      int ma,mb;
      scanf("%d%d%d",&n,&ma,&mb);
      if (!n && !ma && !mb)
         break;
      scanf("%d%d%d%d",&ia,&ib,&da,&db);
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      for (int i=1;i<=ma;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x++,y++;
         a[x][y]=a[y][x]=true;
      }
      for (int i=1;i<=mb;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x++,y++;
         b[x][y]=b[y][x]=true;
      }
      ans=inf;
      memset(f,0,sizeof(f));
      dfs(1);
      printf("Case #%d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
void dfs(int dep)
{
   void update();
   if (dep==n+1)
   {
      update();
      return;
   }
   for (int i=1;i<=n;i++)
   {
      if (f[i])
         continue;
      f[i]=true;
      pos[dep]=i;
      dfs(dep+1);
      f[i]=false;
   }
}
void update()
{
   int sum=0;
   for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      {
         int x=pos[i],y=pos[j];
         if (a[i][j]==b[x][y])
            continue;
         if (a[i][j])
            sum+=min(da,ib);
         else
            sum+=min(ia,db);
      }
   ans=min(ans,sum);
}
