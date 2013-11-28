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
int tot,d[1010],b[1010],a[10010][2],ans[10010][2];
int main()
{
   void bfs(int),print(int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
   }
   tot=0;
   for (int i=1;i<=n;i++)
   {
      memset(d,0,sizeof(d));
      bfs(i);
      print(i);
   }
   printf("%d\n",tot);
   for (int i=1;i<=tot;i++)
      printf("%d %d\n",ans[i][0],ans[i][1]);
   system("pause");
   return(0);
}
int q[1010];
void bfs(int x)
{
   int l,r;
   l=r=1,q[1]=x,d[1]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if (!d[y])
            q[++r]=y;
         d[y]=d[x]+1;
      }
      l++;
   }
}
void print(int x)
{
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (d[y]==d[x]+1)
         ans[++tot][0]=x,ans[tot][1]=y;
   }
}
