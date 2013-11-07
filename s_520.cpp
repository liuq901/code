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
int n,dead[1010],b[1010],a[2010][2];
bool f[1010][1010],vis[1010][1010];
int main()
{
   void bfs();
   bool solve(int,int);
   int m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
      a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
   }
   bfs();
   for (int i=1;i<=n;i++)
      for (int j=dead[i]+1;j<=n+5;j++)
      {
         f[i][j]=true;
         vis[i][j]=true;
      }
   printf("%s\n",solve(1,1)?"Vladimir":"Nikolay");
   system("pause");
   return(0);
}
void bfs()
{
   queue <int> q;
   q.push(1);
   dead[1]=1;
   while (!q.empty())
   {
      int x=q.front();
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if (!dead[y])
         {
            dead[y]=dead[x]+1;
            q.push(y);
         }
      }
      q.pop();
   }
}
bool solve(int x,int y)
{
   if (vis[x][y])
      return(f[x][y]);
   vis[x][y]=true;
   for (int i=b[x];i;i=a[i][1])
   {
      int p=a[i][0];
      if (!solve(p,y+1))
         return(f[x][y]=true);
   }
   return(f[x][y]=false);
}
