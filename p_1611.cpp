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
class UFset
{
   int f[30010],a[30010];
public:
   void init(int n)
   {
      for (int i=1;i<=n;i++)
         f[i]=i,a[i]=1;
   }
   void merge(int x,int y)
   {
      x=find(x),y=find(y);
      if (x==y)
         return;
      a[x]+=a[y];
      f[y]=x;
   }
   int find(int x)
   {
      if (x!=f[x])
         f[x]=find(f[x]);
      return(f[x]);
   }
   int count(int x)
   {
      x=find(x);
      return(a[x]);
   }
};
UFset a;
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      if (!n && !m)
         break;
      a.init(n);
      while (m--)
      {
         int k,t;
         scanf("%d%d",&k,&t);
         k--,t++;
         while (k--)
         {
            int x;
            scanf("%d",&x);
            x++;
            a.merge(t,x);
         }
      }
      printf("%d\n",a.count(1));
   }
   system("pause");
   return(0);
}
