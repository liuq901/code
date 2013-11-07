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
#define MAXN 100010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int inf=1061109567;
int id,pos[MAXN],a[MAXN],b[MAXN];
bool flag[MAXN];
int main()
{
   void tarjan(int),dfs(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=n;i++)
      if (!flag[i])
         tarjan(i);
   int ans=0;
   for (int i=1;i<=n;i++)
      if (pos[i]!=pos[a[i]])
         b[pos[a[i]]]++;
   for (int i=1;i<=pos[0];i++)
      ans+=!b[i];
   printf("%d %d\n",ans,pos[0]);
   system("pause");
   return(0);
}
stack <int> q;
bool f[MAXN];
void tarjan(int x)
{
   bool fail=false;
   int p=x;
   while (!flag[p])
   {
      flag[p]=f[p]=true;
      q.push(p);
      p=a[p];
   }
   if (f[p])
   {
      pos[0]++;
      while (q.top()!=p)
      {
         pos[q.top()]=pos[0];
         f[q.top()]=false;
         q.pop();
      }
      pos[p]=pos[0];
      f[p]=false;
      q.pop();
   }
   while (!q.empty())
   {
      pos[q.top()]=++pos[0];
      f[q.top()]=false;
      q.pop();
   }
}
