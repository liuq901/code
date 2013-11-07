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
#define MAXN 210
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int a[MAXN][MAXN],c[MAXN][MAXN];
int main()
{
   int spfa(int,int);
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      for (int i=0;i<n;i++)
         a[i][0]=0;
      memset(c,63,sizeof(c));
      while (m--)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         if (c[x][y]==inf)
            a[x][++a[x][0]]=y,a[y][++a[y][0]]=x;
         c[x][y]=c[y][x]=min(z,c[x][y]);
      }
      int s,t;
      scanf("%d%d",&s,&t);
      printf("%d\n",spfa(s,t));
   }
   system("pause");
   return(0);
}
int d[MAXN];
queue <int> q;
bitset <MAXN> f;
int spfa(int S,int T)
{
   memset(d,63,sizeof(d));
   q.push(S);
   f.set(S);
   d[S]=0;
   while (!q.empty())
   {
      int x=q.front();
      for (int i=1;i<=a[x][0];i++)
      {
         int y=a[x][i];
         if (d[x]+c[x][y]<d[y])
         {
            d[y]=d[x]+c[x][y];
            if (!f[y])
            {
               f.set(y);
               q.push(y);
            }
         }
      }
      q.pop();
      f.reset(x);
   }
   if (d[T]==inf)
      d[T]=-1;
   return(d[T]);
}
