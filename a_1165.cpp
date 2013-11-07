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
const int c[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int x[MAXN],y[MAXN];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      x[0]=y[0]=0;
      for (int i=1;i<n;i++)
      {
         int p,q;
         scanf("%d%d",&p,&q);
         x[i]=x[p]+c[q][0];
         y[i]=y[p]+c[q][1];
      }
      int minx,miny,maxx,maxy;
      minx=miny=inf,maxx=maxy=0;
      for (int i=0;i<n;i++)
      {
         minx=min(minx,x[i]);
         miny=min(miny,y[i]);
         maxx=max(maxx,x[i]);
         maxy=max(maxy,y[i]);
      }
      printf("%d %d\n",maxx-minx+1,maxy-miny+1);
   }
   system("pause");
   return(0);
}
