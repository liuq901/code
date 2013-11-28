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
map <pair <int,int>,int> a;
int f[400010];
int main()
{
   int find(int);
   void merge(int,int);
   int n;
   scanf("%d",&n);
   int ans=0;
   for (int i=1;i<=n<<1;i++)
      f[i]=i;
   int t=0;
   for (int i=1;i<=n;i++)
   {
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      pair <int,int> p(x1,y1),q(x2,y2);
      if (!a.count(p))
         a[p]=++t;
      if (!a.count(q))
         a[q]=++t;
      int x=a[p],y=a[q];
      if (find(x)==find(y))
      {
         ans=i;
         break;
      }
      merge(x,y);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int find(int x)
{
   if (x!=f[x])
      f[x]=find(f[x]);
   return(f[x]);
}
void merge(int x,int y)
{
   f[find(x)]=find(y);
}
